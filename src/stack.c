// stack.c
#include "stack.h"
#include "log.h"

#include <stdlib.h>


struct Node
{
	struct Node* back;
	long val;
};


struct Stack
{
	struct Node* top;
};


struct Node* new_Node(long val)
{
	struct Node* this = (struct Node*)calloc(1, sizeof(struct Node));
	if(!this) {
		prLog("[!] Error: Allocation error!");
		crash();
	}

	this->val = val;

	return this;
}


void delete_Node(struct Node* this)
{
	this->back = 0;
	this->val = 0;
	free(this);
}


void recursiveDeleteNodes(struct Node* node)
{
	if(node->back != NULL)
		recursiveDeleteNodes(node->back);
	node->back = NULL;
	free(node);
}


struct Stack* new_Stack()
{
	struct Stack* this = (struct Stack*)calloc(1, sizeof(struct Stack));
	if(!this) {
		prLog("[!] Error: Allocation error!");
		crash();
	}

	return this;
}


void delete_Stack(struct Stack* this)
{
	if(!this) {
		prLog("[!] Error: Object not initialize!");
		crash();
	}
	if(this->top != NULL)
		recursiveDeleteNodes(this->top);
	this->top = NULL;
	free(this);
}


void push_Stack(struct Stack* this, long val)
{
	if(!this) {
		prLog("[!] Error: Object (Stack) not initialize!");
		crash();
	}
	struct Node* newNode = new_Node(val);
	newNode->back = this->top;
	this->top = newNode;
}


long pop_Stack(struct Stack* this)
{
	if(!this) {
		prLog("[!] Error: Object (Stack) not initialized!");
		crash();
	}
	if(!this->top) {
		prLog("[!] Error: Stack is empty!\n");
		crash();
	}
	struct Node* oldNode = this->top;
	this->top = this->top->back;
	long oldVal = oldNode->val;
	delete_Node(oldNode);

	return oldVal;
}


int isEmpty_Stack(struct Stack* this)
{
	if(!this) {
		prLog("[!] Error: Object (Stack) not initialize!");
		crash();
	}
	return !(this->top);
}
