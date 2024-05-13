MEMORY
{
    RAM : ORIGIN = 0x8000, LENGTH = 256K
}

SECTIONS
{
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
