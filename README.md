# 3ds-ruby

**Compiling mruby**:<br>Firstly, drag and drop the `nintendo_3ds.rb` onto mruby's build_config folder and then run the following command (assuming you are onto the [mruby's](https://github.com/mruby/mruby) project folder at)<br>`clear;rake MRUBY_CONFIG=nintendo_3ds -j$(nproc) clean all&&sudo cp -r build/nintendo_3ds_devkitARM/lib /opt/devkitpro/portlibs/3ds/.` <br>
NOTE: i did not put all gems to compile, because some gems won't compile. You can add your own gem with `conf.gem` by modifying the `nintendo_3ds.rb` file.

**Compiling this Project**:<br>This is the command i use to run the project: <br> `clear;make clean;make&&flatpak run org.citra_emu.citra 3ds-ruby.3dsx` <br> You'll need to run `mrbc -o romfs/ruby/main.mrb source/main.rb` to convert the Ruby file onto bytecode if you are only going to use bytecode files. If you are NOT going to use bytecode, see the next header.

**Using compile**:<br>To use compile instead of bytecode, open `nintendo_3ds.rb` and uncomment `conf.gem :core => 'mruby-compiler'`. <br> Now open `main.c` and modify `mrb_load_irep_file(mrb, f)` to `mrb_load_file(mrb, f)`.<br>Remember to also change the file path, and move the `main.rb` onto `romfs/ruby`

### TODO
- Make the Makefile automatically convert Ruby files to bytecode. And a bunch of other stuff to do with the Makefile.
- Add more bindings.
- <s>Somehow make Ruby exit and return to the C code.
