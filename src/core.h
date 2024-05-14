#ifndef CORE_H
#define CORE_H

void core1_function();
void core2_function();
void core3_function();
void start_core(int core_id, void (*func)(void));
void start_core(int core_id, void (*task_func)(void));

#endif
// In core.h


#include "uart.h"
#include "mbox.h"

#define str_size 40
#define ENTER_KEY 10
#define BACKSPACE_KEY 8
#define DELETE_KEY 127
#define SPACE_CHAR 32

const char *readUserInput();
void set_text_color(char text[]);
void set_background_color(char background[]);

void displayMenu();
void wait_ms(unsigned int n);
