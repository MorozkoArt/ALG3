#pragma once
#include "Node.h"

typedef struct Stack {
	int size;
	int limit;
	Node** data;
} Stack;
Stack* createStack();
void push(Stack* s, Node* item);
Node* pop(Stack* s);
Node* peek(Stack* s);
