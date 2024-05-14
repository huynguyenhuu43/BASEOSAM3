MEMORY
{
    RAM : ORIGIN = 0x8000, LENGTH = 256K
}

SECTIONS
{
    . = 0x80000;     /* Kernel load address for AArch64 */
    .text : { KEEP(*(.text.boot)) *(.text .text.* .gnu.linkonce.t*) }
    .rodata : { *(.rodata .rodata.* .gnu.linkonce.r*) }
    PROVIDE(_data = .);
    .data : { *(.data .data.* .gnu.linkonce.d*) }
    .bss (NOLOAD) : {
        . = ALIGN(16);
        __bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    }
    _end = .;

    /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) }

    .text : {
       *(.text)    /* All text code */
       . = ALIGN(4);
    }

    .data : {
       *(.data)    /* All initialized data */
       . = ALIGN(4);
    }

    .bss : {
       *(.bss)     /* All uninitialized variables */
       . = ALIGN(4);
    }
}
__bss_size = (__bss_end - __bss_start)>>3;
