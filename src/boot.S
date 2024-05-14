.section ".text.boot"  // Make sure the linker puts this at the start of the kernel image

.global _start  // Execution starts here

_start:
    // Check processor ID is zero (executing on main core), else hang
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbz     x1, 2f
    // We're not on the main core, so hang in an infinite wait loop
1:  wfe
    b       1b
2:  // We're on the main core!

    // Set stack to start below our code
    ldr     x1, =_start
    mov     sp, x1

    // Clean the BSS section
    ldr     x1, =__bss_start     // Start address
    ldr     w2, =__bss_size      // Size of the section
3:  cbz     w2, 4f               // Quit loop if zero
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, 3b               // Loop if non-zero

    // Call init_system if it's core 0, otherwise wait
    mrs     x0, mpidr_el1            // Read MPIDR to obtain information about the current core
    and     x0, x0, #3               // Only take the lowest 2 bits to determine the core ID
    cbz     x0, core0_start          // If it is core 0, jump to core0_start
1:  wfe                               // Wait for event
    b       1b                       // Continue waiting in the loop

core0_start:
    bl      init_system               // Call the system initialization function
    b       main                      // Jump to the main function in C

// System initialization function
init_system:
    // Setup stacks and necessary configurations
    ret                               // Return after initialization

.global main
main:
    ldr     x0, =main                // Address of the main function in C
    br      x0                        // Jump to the main function
