CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=cortex-a72 -fpic -ffreestanding
ASFLAGS=-mcpu=cortex-a72
LDFLAGS=-T linker.ld

GCCFLAGS=-Wall -O2 -ffreestanding -nostdinc -nostdlib

CFILES=$(wildcard ./src/*.c)
OFILES=$(CFILES:./src/%.c=./build/%.o)

all: clean kernel8.img run

./build/boot.o: ./src/boot.S
    $(AS) $(ASFLAGS) $< -o $@

./build/%.o: ./src/%.c 
    $(CC) $(GCCFLAGS) -c $< -o $@

kernel8.img: ./build/boot.o $(OFILES)
    $(LD) -nostdlib ./build/boot.o $(OFILES) -T ./src/link.ld -o ./build/kernel8.elf
    $(OBJCOPY) -O binary ./build/kernel8.elf kernel8.img

clean:
    rm -f ./build/kernel8.elf ./build/*.o *.img

run: 
    qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial stdio
