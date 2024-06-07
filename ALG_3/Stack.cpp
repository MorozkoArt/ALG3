#define _CRT_SECURE_NO_WARNINGS
#define STACK_INIT_SIZE 100
#include "Stack.h"
#include "Node.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include <algorithm>
using namespace std;




Stack* createStack() 
{
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->limit = STACK_INIT_SIZE;
	tmp->size = 0;
	tmp->data = (Node**)malloc(tmp->limit * sizeof(Node*));
	return tmp;
}

void push(Stack* s, Node* item)
{
	s->data[s->size++] = item;

}

Node* pop(Stack* s)
{
	if (s->size == 0)
	{
		return 0;
	}
	s->size--;
	return s->data[s->size];
}

Node* peek(Stack* s)
{
	return s->data[s->size - 1];
}