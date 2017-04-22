

rm *.o
rm image.elf image.hex

#VARIABLE
export TOOLS="/home/mike/Software/x-tools/arm-none-eabi/bin"

#BUILD
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles boot.c 
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles vector.c 
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles main.c 

#LINK
$TOOLS/arm-none-eabi-gcc -g -fno-builtin -nostdlib -nostartfiles -T lpc1769.ld boot.o vector.o main.o -o image.elf

#REFORMAT
/home/mike/Software/x-tools/arm-none-eabi/bin/arm-none-eabi-objcopy -O ihex image.elf image.hex

#LOAD
/home/mike/Software/x-tools/lpc21isp image.hex /dev/ttyUSB6 115200 14746

