// In the first snippet
#include "uart.h"
#include "core.h"
#include "mbox.h"
#include "framebf.h"
#include <stdio.h>  // Write functions to output data to hardware

// Define core tasks
void core1_task(void) {
    while (1) {
        printf("Core 1: Analyzing sensor data.\n");
        // Simulate the analysis process
        for (volatile int i = 0; i < 1000000; i++);
    }
}

void core2_task(void) {
    while (1) {
        // Simulate performing a task, e.g., image processing
        printf("Core 2: Processing images.\n");
        // Simulate the image processing process
        for (volatile int i = 0; i < 1000000; i++);
    }
}

void core3_task(void) {
    while (1) {
        // Simulate performing a task, e.g., data storage
        printf("Core 3: Storing data.\n");
        // Simulate the data storage process
        for (volatile int i = 0; i < 1000000; i++);
    }
}

// Main function
int main() {
    uart_configure(&config);
    colorsInit();
    framebf_init(SCR_WIDTH, SCR_HEIGHT);
    displayMenu();
    drawOnScreen();

    // Start other cores
    start_core(1, core1_task);
    start_core(2, core2_task);
    start_core(3, core3_task);

    while (1) {
        uart_puts("\n\n");
        char c = uart_getc();
        uart_sendc(c);
        uart_sendc('\n');

        switch (c) {
            case '1':
                // Handle command 1
                break;
            case '2':
                // Handle command 2
                break;
            case '3':
                // Handle command 3
                break;
            case '4':
                playVideo();
                break;
            case '5':
                // Handle command 5
                break;
            case '0':
                clearScreen(COLORS.BLACK);
                uart_puts("All cleared!");
                break;
            default:
                uart_puts("Invalid command. Please try again");
                break;
        }
    }

    return 0;
}
