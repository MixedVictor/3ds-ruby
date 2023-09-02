Ctru::Console.init(Ctru::Gfx::GFX_TOP)

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
    puts "Press A to refresh, or START to exit."
end

print_concat

while true
    Ctru::Control.hid_scan_input
    
    if (Ctru::Control.hid_keys_down == Ctru::Hid::KEY_A)
        Ctru::Console.clear
        print_concat
        puts "Refreshed!"
    end
    if (Ctru::Control.hid_keys_down == Ctru::Hid::KEY_START)
        # TODO: exit this.
    end    
end