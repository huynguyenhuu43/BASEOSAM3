#include "core.h"
#include <stdio.h>  // Write functions to output data to hardware

// Declare functions
void core1_task(void);
void core2_task(void);
void core3_task(void);

void core1_task() {
    while (1) {
      
        printf("Core 1: Analyzing sensor data.\n");
        // Simulate the analysis process
        for (volatile int i = 0; i < 1000000; i++); 
    }
}

void core2_task() {
    while (1) {
        // Simulate performing a task, e.g., image processing
        printf("Core 2: Processing images.\n");
        // Simulate the image processing process
        for (volatile int i = 0; i < 1000000; i++); 
    }
}

void core3_task() {
    while (1) {
        // Simulate performing a task, e.g., data storage
        printf("Core 3: Storing data.\n");
        // Simulate the data storage process
        for (volatile int i = 0; i < 1000000; i++); 
    }
}


void start_core(int core_id, void (*task_func)(void)) {
    // In real bare-metal scenarios, customize this as needed
    // 1. Send a signal to start the core with the corresponding ID.
    // 2. Ensure that core executes the specified function.
    
    switch (core_id) {
        case 1:
            core1_task();
            break;
        case 2:
            core2_task();
            break;
        case 3:
            core3_task();
            break;
        default:
            // Report an error if the core ID is invalid
            printf("Error: Invalid core ID.\n");
            break;
    }
}
