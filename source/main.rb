Ctru::Console.init(Ctru::Gfx::GFX_TOP, nil)

class Concat
    def initialize(str, strs)
        @str = str
        @strs = strs
    end
    def get_rand_str
        return @strs[rand(@strs.length)]
    end
    def rand_strs_on_str
        return get_rand_str + " " + @str + " " + get_rand_str
    end
end

$my_str = "Hello world!"
$my_strs = ["Random", "String", "Test"]

$conc = Concat.new($my_str, $my_strs)

def print_concat
    puts $conc.rand_strs_on_str
    puts "Press A or touch screen to refresh, or START to exit Ruby."
end

print_concat

while Ctru::Apt::main_loop
    Ctru::Hid.scan_input
    
    if (Ctru::Hid.keys_down == Ctru::Hid::KEY_A ||
        Ctru::Hid.keys_down == Ctru::Hid::KEY_TOUCH
        )
        Ctru::Console.clear
        print_concat
        puts "Refreshed!"
    end
    if (Ctru::Hid.keys_down == Ctru::Hid::KEY_START)
        exit
    end

    Ctru::Gfx.flush_buffers
    Ctru::Gfx.swap_buffers
    Ctru::Gsp.wait_for_vblank
end