
#VARIABLE
export TOOLS="/home/mike/x-tools/arm-unknown-eabi/bin"
export COMPILER="$TOOLS/arm-unknown-eabi-gcc"
export LINKER="$TOOLS/arm-unknown-eabi-gcc"
export OBJCOPY="$TOOLS/arm-unknown-eabi-objcopy"
export FLASH="/home/mike/x-tools/lpc21isp"
export CC_ARGS="-W -Wall -c -g -fno-builtin -nostdlib -nostartfiles"
export LINK_SCRIPT="lpc824.ld"
export LINK_ARGS="   -g -fno-builtin -nostdlib -nostartfiles -T $LINK_SCRIPT"

#BUILD
$COMPILER  $CC_ARGS boot.c 
$COMPILER  $CC_ARGS vector.c 
$COMPILER  $CC_ARGS hd44780.c 
$COMPILER  $CC_ARGS main.c 

#LINK
$LINKER $LINK_ARGS boot.o vector.o main.o hd44780.o -o image.elf

#REFORMAT
$OBJCOPY -O ihex image.elf image.hex

#LOAD
$FLASH image.hex /dev/ttyUSB9 115200 14746

