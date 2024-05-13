#ifndef CORE_H
#define CORE_H

void core1_function();
void core2_function();
void core3_function();
void start_core(int core_id, void (*func)(void));

#endif

