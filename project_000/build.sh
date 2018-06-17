
#VARIABLE
export TOOLS="/home/mike/x-tools/arm-none-eabi/bin"

#BUILD
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles meminit.c 
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles startup.c 
$TOOLS/arm-none-eabi-gcc -c -g -fno-builtin -nostdlib -nostartfiles main.c 

#LINK
$TOOLS/arm-none-eabi-gcc -g -fno-builtin -nostdlib -nostartfiles -T lpc1769.ld meminit.o startup.o main.o -o image.elf

#REFORMAT
$TOOLS/arm-none-eabi-objcopy -O ihex image.elf image.hex

#LOAD
#set p2.10 low
#reset low 
#wait 1 second 
#reset high
#wait 1 second
#set p2.10 high
#run loader:
/home/mike/x-tools/lpc21isp image.hex /dev/ttySAC0 115200 14746

#echo 0 > /sys/class/gpio/gpio19/value
#echo 0 > /sys/class/gpio/gpio173/value
#cat /sys/class/gpio/gpio19/value
#cat /sys/class/gpio/gpio173/value
#sleep 1 
#echo 1 > /sys/class/gpio/gpio19/value
#/home/mike/x-tools/lpc21isp image.hex /dev/ttySAC0 115200 14746
#
#echo 1 > /sys/class/gpio/gpio173/value
#echo 0 > /sys/class/gpio/gpio19/value
#sleep 1 
#echo 1 > /sys/class/gpio/gpio19/value






