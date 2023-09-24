#include <3ds.h>

#include <mruby.h>
#include <mruby/dump.h>

#include "rctru.h"

void exit_loop(void)
{
    printf("\nPress START or touch screen to exit.");
    while (aptMainLoop())
    {
        hidScanInput();
        if (hidKeysDown() == KEY_START ||
            hidKeysDown() == KEY_TOUCH)
            break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }
}

int main(void)
{
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);

    Result rc = romfsInit();
    if (rc)
    {
        printf("romfsInit: %08lX\n", rc);
        exit_loop();
    }
    else
    {
        mrb_state *mrb = mrb_open();

        // Init ctru gem.
        mrb_ctru_gem_init(mrb);

        FILE *f = fopen("romfs:/main.mrb", "r");
        if (f == NULL)
        {
            printf("main.mrb load failed.");
            exit_loop();
        }
        else
        {
            mrb_load_irep_file(mrb, f);
            if (mrb->exc)
            {
                consoleClear();
                mrb_p(mrb, mrb_obj_value(mrb->exc));
                exit_loop();
            }
            else
                gfxExit();
        }
        mrb_close(mrb);
        fclose(f);
    }
    gfxExit();
    return 0;
}