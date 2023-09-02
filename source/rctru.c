#include "rctru.h"

// Console class.
static mrb_value mrb_console_init(mrb_state *mrb, mrb_value self)
{
    // TODO: improve this.
    mrb_int screen;
    mrb_get_args(mrb, "i", &screen);
    consoleInit(screen, NULL);
    return mrb_nil_value();
}
// TODO: create this.
// static mrb_value mrb_console_select(mrb_state *mrb, mrb_value self)
// {
//     mrb_int screen;
//     mrb_get_args(mrb, "i", &screen);
//     consoleSelect();
//     return mrb_nil_value();
// }
static mrb_value mrb_console_clear(mrb_state *mrb, mrb_value self)
{
    consoleClear();
    return mrb_nil_value();
}

// Control class.
static mrb_value mrb_hid_scan_input(mrb_state *mrb, mrb_value self)
{
    hidScanInput();
    return mrb_nil_value();
}
static mrb_value mrb_hid_keys_down(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(hidKeysDown());
}

void mrb_ctru_gem_init(mrb_state *mrb)
{
    struct RClass *ctru = mrb_define_module(mrb, "Ctru");

    struct RClass *console = mrb_define_module_under(mrb, ctru, "Console");
    mrb_define_class_method(mrb, console, "init",
                            mrb_console_init, MRB_ARGS_REQ(1));
    // mrb_define_class_method(mrb, console, "select",
    //                         mrb_console_init, MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb, console, "clear",
                            mrb_console_clear, MRB_ARGS_NONE());

    struct RClass *control = mrb_define_module_under(mrb, ctru, "Control");
    mrb_define_class_method(mrb, control, "hid_scan_input",
                            mrb_hid_scan_input, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, control, "hid_keys_down",
                            mrb_hid_keys_down, MRB_ARGS_NONE());

    struct RClass *gfx = mrb_define_module_under(mrb, ctru, "Gfx");
    mrb_define_const(mrb, gfx, "GFX_TOP", mrb_fixnum_value(GFX_TOP));
    mrb_define_const(mrb, gfx, "GFX_BOTTOM", mrb_fixnum_value(GFX_BOTTOM));

    // Control enum.
    struct RClass *hid = mrb_define_module_under(mrb, ctru, "Hid");
    mrb_define_const(mrb, hid, "KEY_A", mrb_fixnum_value(KEY_A));
    mrb_define_const(mrb, hid, "KEY_B", mrb_fixnum_value(KEY_B));
    mrb_define_const(mrb, hid, "KEY_SELECT", mrb_fixnum_value(KEY_SELECT));
    mrb_define_const(mrb, hid, "KEY_START", mrb_fixnum_value(KEY_START));
    mrb_define_const(mrb, hid, "KEY_DRIGHT", mrb_fixnum_value(KEY_DRIGHT));
    mrb_define_const(mrb, hid, "KEY_DLEFT", mrb_fixnum_value(KEY_DLEFT));
    mrb_define_const(mrb, hid, "KEY_DUP", mrb_fixnum_value(KEY_DUP));
    mrb_define_const(mrb, hid, "KEY_DDOWN", mrb_fixnum_value(KEY_DDOWN));
    mrb_define_const(mrb, hid, "KEY_R", mrb_fixnum_value(KEY_R));
    mrb_define_const(mrb, hid, "KEY_L", mrb_fixnum_value(KEY_L));
    mrb_define_const(mrb, hid, "KEY_X", mrb_fixnum_value(KEY_X));
    mrb_define_const(mrb, hid, "KEY_Y", mrb_fixnum_value(KEY_Y));
    mrb_define_const(mrb, hid, "KEY_ZL", mrb_fixnum_value(KEY_ZL));
    mrb_define_const(mrb, hid, "KEY_ZR", mrb_fixnum_value(KEY_ZR));
    mrb_define_const(mrb, hid, "KEY_TOUCH", mrb_fixnum_value(KEY_TOUCH));
    mrb_define_const(mrb, hid, "KEY_CSTICK_RIGHT", mrb_fixnum_value(KEY_CSTICK_RIGHT));
    mrb_define_const(mrb, hid, "KEY_CSTICK_LEFT", mrb_fixnum_value(KEY_CSTICK_LEFT));
    mrb_define_const(mrb, hid, "KEY_CSTICK_UP", mrb_fixnum_value(KEY_CSTICK_UP));
    mrb_define_const(mrb, hid, "KEY_CSTICK_DOWN", mrb_fixnum_value(KEY_CSTICK_DOWN));
    mrb_define_const(mrb, hid, "KEY_CPAD_RIGHT", mrb_fixnum_value(KEY_CPAD_RIGHT));
    mrb_define_const(mrb, hid, "KEY_CPAD_LEFT", mrb_fixnum_value(KEY_CPAD_LEFT));
    mrb_define_const(mrb, hid, "KEY_CPAD_UP", mrb_fixnum_value(KEY_CPAD_UP));
    mrb_define_const(mrb, hid, "KEY_CPAD_DOWN", mrb_fixnum_value(KEY_CPAD_DOWN));

    // Generic catch-all directions
    mrb_define_const(mrb, hid, "KEY_UP", mrb_fixnum_value(KEY_UP));
    mrb_define_const(mrb, hid, "KEY_DOWN", mrb_fixnum_value(KEY_DOWN));
    mrb_define_const(mrb, hid, "KEY_LEFT", mrb_fixnum_value(KEY_LEFT));
    mrb_define_const(mrb, hid, "KEY_RIGHT", mrb_fixnum_value(KEY_RIGHT));
}
