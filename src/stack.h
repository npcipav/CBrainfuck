// stack.h

/*
 * Стек. Информация добавляется в- и снимается с- вершины.
 */

#ifndef STACK_H
#define STACK_H

struct Stack;

struct Stack* new_Stack();
void delete_Stack(struct Stack* this);

void push_Stack(struct Stack* this, long val);
long pop_Stack(struct Stack* this);
int  isEmpty_Stack(struct Stack* this);


typedef struct Stack* STACK;

#endif

