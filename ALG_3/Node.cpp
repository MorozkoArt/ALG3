#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include <algorithm>
using namespace std;

Node* New(int data)
{
	Node* V;
	V = (Node*)malloc(sizeof Node);
	V->info = data;
	V->left = NULL;
	V->right = NULL;
	return V;
};

Node* Add(Node* v, int data)
{
	if (v == NULL)
		return New(data);
	if (v->info < data)
		v->right = Add(v->right, data);
	else
		v->left = Add(v->left, data);
	return v;
};

void Print(Node* v)
{
	static int n = 0;//������� �������
	if (!v) return;// ���� � ��������� ��������
	n++;
	Print(v->right); // ����� ������� ���������
	printf("(Level %d) %d\n", n, v->info); // ����� ���������� � �������
	Print(v->left); // ����� ������ ���������
	n--;
}

void Pre_order(Node* v)
{
	if (v == NULL)
		return;// ���� � ��������� ��������
	printf("%d ", v->info); // ����� ���������� � �������
	Pre_order(v->left); // ����� ������ ���������
	Pre_order(v->right); // ����� ������� ���������
}

void In_order(Node* v)
{
	if (v == NULL) return;
	In_order(v->left); // ����� ������ ���������
	printf("%d ", v->info);
	In_order(v->right); // ����� ������� ���������
}

void Post_order(Node* v)
{
	if (v == NULL) return;// ���� � ��������� ��������
	Post_order(v->left); // ����� ������ ���������
	Post_order(v->right);
	printf("%d ", v->info);// ����� ������� ���������
}
int height(Node* v)
{
	if (v == NULL)
	{
		return 0;
	}
	return 1 + max(height(v->left), height(v->right));
}

int list_count(Node* v)
{
	if (!v)
		return 0;
	if (!v->left && !v->right)
		return 1;
	return list_count(v->left) + list_count(v->right);
}

void iterPreorder(Node* v) 
{
	Stack* stack = createStack();
	while (stack->size != 0 || v != NULL) 
	{
		if (v != NULL) 
		{
			printf("%d ", v->info);
			if (v->right) 
			{
				push(stack, v->right);
			}
			v = v->left;
		}
		else 
		{
			v = pop(stack);
		}
	}
}

void DelTree(Node** v)
{
	if (*v)
	{
		DelTree(&((*v)->left));
		DelTree(&((*v)->right));
		free(*v);
	}
}