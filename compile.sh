x86_64-elf-gcc -c -g -ffreestanding *.c
nasm -f elf64 header.asm -o header.o
nasm -f elf64 main.asm -o mainasm.o
nasm -f elf64 main64.asm -o main64.o
x86_64-elf-ld -n -o kernel.bin -T linker.ld *.o
cp kernel.bin isodir/boot/kernel.bin
grub-mkrescue -o kernel.iso isodir
rm isodir/boot/kernel.bin *.o
cp kernel.iso /media/sf_fvm/kernel.iso
qemu-system-x86_64 kernel.iso
