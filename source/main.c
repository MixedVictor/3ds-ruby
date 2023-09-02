#include <3ds.h>

#include <mruby.h>
#include <mruby/dump.h>

#include "rctru.h"

int main(void)
{
    gfxInitDefault();

    Result rc = romfsInit();
    if (rc)
        printf("romfsInit: %08lX\n", rc);
    else
    {
        mrb_state *mrb = mrb_open();

        // Init ctru gem.
        mrb_ctru_gem_init(mrb);

        FILE *f = fopen("romfs:/ruby/main.mrb", "r");
        if (f == NULL)
            printf("main.mrb load failed.");
        else
        {
            mrb_load_irep_file(mrb, f);
            if (mrb->exc)
                mrb_p(mrb, mrb_obj_value(mrb->exc));
        }
        mrb_close(mrb);
        fclose(f);
    }

    while (aptMainLoop())
    {
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }
    
    gfxExit();
    return 0;
}