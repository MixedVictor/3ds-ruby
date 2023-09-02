# Tested on linux
# Based on the nintendo_switch.rb file
MRuby::CrossBuild.new('nintendo_3ds_devkitARM') do |conf|
  conf.toolchain :gcc

  # I did not put all gems, so you'll have to add them if you want to.
  # Also, 'mruby-compiler' might be disabled since i prefer compiling the ruby code directly to bytecode.
  # conf.gem :core => 'mruby-compiler'
  conf.gem :core => 'mruby-print'
  conf.gem :core => 'mruby-time'
  conf.gem :core => 'mruby-random'

  DEVKITPRO_PATH = '/opt/devkitpro'
  DEVKITARM_PATH = '/opt/devkitpro/devkitARM'

  include_paths = [
    "#{DEVKITARM_PATH}/arm-none-eabi/include",
    "#{DEVKITPRO_PATH}/libctru/include",
  ]

  conf.cc do |cc|
    cc.command = "#{DEVKITARM_PATH}/bin/arm-none-eabi-gcc"
    cc.include_paths += include_paths
    cc.flags += ['-O2 -mword-relocations -ffunction-sections -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -D__3DS__']
  end

  conf.cxx do |cxx|
    cxx.command = "#{DEVKITARM_PATH}/bin/arm-none-eabi-g++"
    cxx.include_paths += include_paths
    cxx.flags += ['-O2 -mword-relocations -ffunction-sections -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -D__3DS__ -fno-rtti -fno-exceptions -std=gnu++11']
  end

  conf.archiver do |archiver|
    archiver.command = "#{DEVKITARM_PATH}/bin/arm-none-eabi-ar"
  end

  conf.linker do |linker|
    linker.command = "#{DEVKITARM_PATH}/bin/arm-none-eabi-g++"
    linker.flags = ["-march=armv6k", "-mtune=mpcore", "-mfloat-abi=hard", "-mtp=soft"]
    linker.libraries = []
  end
end
