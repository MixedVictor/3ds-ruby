# 3ds-ruby

Finally, a scripting language for the 3DS that is easy to install and embeddable!

## Installing mruby

#### Compiling and installing mruby
Firstly, drag and drop the `nintendo_3ds.rb` onto mruby's build_config folder and then run the following commands (assuming you are onto the [mruby's](https://github.com/mruby/mruby) project folder):<br>
```
# Clear the screen to make it nicer.
clear
# Firstly, compile and install the system's mruby.
sudo ./minirake all
# Now, we compile 3DS's mruby.
sudo ./minirake MRUBY_CONFIG=nintendo_3ds all
# Copy the recently compiled library folder to portlibs.
sudo cp -r build/nintendo_3ds_devkitARM/lib /opt/devkitpro/portlibs/3ds/.
# Copy the mruby's include folder to portlibs.
sudo cp -r include /opt/devkitpro/portlibs/3ds/.
```
If something went wrong you can do `rake clean` and recompile everything.<br>
**NOTE:** i did not put all gems to compile (because some gems won't compile). You can add your own gem with `conf.gem` by modifying the `nintendo_3ds.rb` file.

## Using the Project

#### Compiling this Project
This is the command i use to run the project: 
```
clear;make clean;make&&flatpak run org.citra_emu.citra 3ds-ruby.3dsx
```
**NOTE:** the Makefile will convert all ruby code inside the `source` folder. If you are NOT going to use bytecode, see the next header.

#### Using compile 
To use compile instead of bytecode, open `nintendo_3ds.rb` and uncomment `conf.gem :core => 'mruby-compiler'`. <br> Now open `main.c` and change `mrb_load_irep_file(mrb, f)` to `mrb_load_file(mrb, f)`.<br>Remember to also change the file path, and move the `main.rb` to the `romfs` folder.

## TODO
- [ ] Add more bindings.
- [x] Somehow make the Makefile automatically convert Ruby files to bytecode. And a bunch of other stuff to do with the Makefile.
- [x] Somehow make Ruby exit and return to the C code.
