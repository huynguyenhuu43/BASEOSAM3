#include "core.h"

void main_core() {
    printf("Main core has started.\n");
    start_core(1, secondary_core);
    start_core(2, secondary_core);
    start_core(3, secondary_core);

    while(1) {
        // Main loop to keep this core active
        perform_main_tasks();
    }
}

void secondary_core() {
    printf("Secondary core has started.\n");
    while(1) {
        perform_secondary_tasks();
    }
}

void perform_main_tasks() {
    // Setup according to requirements
}

void perform_secondary_tasks() {
    // Setup according to requirements
}

void start_core(int core_id, void (*func)(void *)) {
    // Start the core with the provided function address
    unsigned long *reg = (unsigned long *)(0xE0000000 + 0x8 * core_id);
    *reg = (unsigned long)func;
    __sev();                        // Send event to wake up cores
}
