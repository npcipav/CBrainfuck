// stack_test.c

/*
 * Тест работы стека.
 */

#include "stack.h"

#include <stdio.h>


int main(void)
{
	STACK stack = new_Stack();
	for(int i = 0L; i < 10L; i++)
		push_Stack(stack, i);
	while(!isEmpty_Stack(stack))
		printf("%ld\n", pop_Stack(stack));
	delete_Stack(stack);
}
