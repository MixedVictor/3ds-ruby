#include "rctru.h"

// Apt class.

static mrb_value mrb_ctru_apt_main_loop(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(aptMainLoop());
}

// Console class.

static mrb_value mrb_ctru_console_init(mrb_state *mrb, mrb_value self)
{
    gfxScreen_t screen;
    PrintConsole *console;
    mrb_get_args(mrb, "io", &screen, &console);
    return mrb_fixnum_value((int)consoleInit(screen, console));
}
static mrb_value mrb_ctru_console_select(mrb_state *mrb, mrb_value self)
{
    PrintConsole *console;
    mrb_get_args(mrb, "o", &console);
    return mrb_fixnum_value((int)consoleSelect(console));
}
static mrb_value mrb_ctru_console_clear(mrb_state *mrb, mrb_value obj)
{
    consoleClear();
    return mrb_nil_value();
}

// Gfx class.

static mrb_value mrb_ctru_gfx_flush_buffers(mrb_state *mrb, mrb_value obj)
{
    gfxFlushBuffers();
    return mrb_nil_value();
}
static mrb_value mrb_ctru_gfx_swap_buffers(mrb_state *mrb, mrb_value obj)
{
    gfxSwapBuffers();
    return mrb_nil_value();
}

// Gsp class.

static mrb_value mrb_ctru_gsp_wait_for_vblank(mrb_state *mrb, mrb_value obj)
{
    gspWaitForVBlank();
    return mrb_nil_value();
}

// Hid class.

static mrb_value mrb_ctru_hid_scan_input(mrb_state *mrb, mrb_value obj)
{
    hidScanInput();
    return mrb_nil_value();
}
static mrb_value mrb_ctru_hid_keys_down(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(hidKeysDown());
}

void mrb_ctru_gem_init(mrb_state *mrb)
{
    struct RClass *ctru = mrb_define_module(mrb, "Ctru");

    struct RClass *apt = mrb_define_module(mrb, "Apt");
    mrb_define_class_method(mrb, apt, "main_loop", mrb_ctru_apt_main_loop, MRB_ARGS_NONE());

    struct RClass *console = mrb_define_module_under(mrb, ctru, "Console");
    mrb_define_class_method(mrb, console, "init", mrb_ctru_console_init, MRB_ARGS_REQ(2));
    mrb_define_class_method(mrb, console, "clear", mrb_ctru_console_clear, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, console, "select", mrb_ctru_console_select, MRB_ARGS_REQ(1));

    // printconsole = mrb_define_module_under(mrb, console, "PrintConsole");
    // mrb_define_class_method(mrb, printconsole, "new", mrb_ctru_console_printconsole_new, MRB_ARGS_NONE());

    struct RClass *gfx = mrb_define_module_under(mrb, ctru, "Gfx");
    mrb_define_class_method(mrb, gfx, "flush_buffers", mrb_ctru_gfx_flush_buffers, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, gfx, "swap_buffers", mrb_ctru_gfx_swap_buffers, MRB_ARGS_NONE());

    mrb_define_const(mrb, gfx, "GFX_TOP", mrb_fixnum_value(GFX_TOP));
    mrb_define_const(mrb, gfx, "GFX_BOTTOM", mrb_fixnum_value(GFX_BOTTOM));

    struct RClass *gsp = mrb_define_module_under(mrb, ctru, "Gsp");
    mrb_define_class_method(mrb, gsp, "wait_for_vblank", mrb_ctru_gsp_wait_for_vblank, MRB_ARGS_NONE());

    struct RClass *hid = mrb_define_module_under(mrb, ctru, "Hid");
    mrb_define_class_method(mrb, hid, "scan_input", mrb_ctru_hid_scan_input, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, hid, "keys_down", mrb_ctru_hid_keys_down, MRB_ARGS_NONE());

    // Removed most of the controls because i don't need all of then.
    // And i don't want them to be too long too.
    mrb_define_const(mrb, hid, "KEY_A", mrb_fixnum_value(KEY_A));
    mrb_define_const(mrb, hid, "KEY_B", mrb_fixnum_value(KEY_B));
    mrb_define_const(mrb, hid, "KEY_SELECT", mrb_fixnum_value(KEY_SELECT));
    mrb_define_const(mrb, hid, "KEY_START", mrb_fixnum_value(KEY_START));
    mrb_define_const(mrb, hid, "KEY_X", mrb_fixnum_value(KEY_X));
    mrb_define_const(mrb, hid, "KEY_Y", mrb_fixnum_value(KEY_Y));
    mrb_define_const(mrb, hid, "KEY_TOUCH", mrb_fixnum_value(KEY_TOUCH));

    // DPAD and CPAD.
    mrb_define_const(mrb, hid, "KEY_UP", mrb_fixnum_value(KEY_UP));
    mrb_define_const(mrb, hid, "KEY_DOWN", mrb_fixnum_value(KEY_DOWN));
    mrb_define_const(mrb, hid, "KEY_LEFT", mrb_fixnum_value(KEY_LEFT));
    mrb_define_const(mrb, hid, "KEY_RIGHT", mrb_fixnum_value(KEY_RIGHT));
}
