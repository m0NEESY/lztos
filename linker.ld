ENTRY(start)

SECTIONS
{
  . = 0x100000;

  .multiboot2_header :
  {
    *(.multiboot2_header)
  }

  .text :
  {
    *(.text)
  }
  .rodata :
  {
    *(.rodata*)
  }
  .bss :
  {
    *(.bss)
  }
  /DISCARD/ : {
    *(.comment)
  }
}
