#define _CRT_SECURE_NO_WARNINGS
#define STACK_INIT_SIZE 100
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Stack.h"

int main()
{
	setlocale(LC_ALL, "Ru");
	const int N = 9;
	int mass[N];
	FILE* VD;
	if ((VD = fopen("VD.txt", "r")) == NULL)
	{
		printf("Не удалось открыть файл");
		getchar();
		return 0;
	}
	for (int i = 0; i < N; i++) 
	{
		if (fscanf(VD, "%d", &mass[i]) == EOF) break;
		printf("%d ", mass[i]);
	}

	Node* V = NULL;
	for (int i = 0; i < N; i++)
		V = Add(V, mass[i]);
	printf("\n");
	Print(V);
	printf("Pre_order: ");
	Pre_order(V);
	printf("\n");
	printf("In_order: ");
	In_order(V);
	printf("\n");
	printf("Post_order: ");
	Post_order(V);
	printf("\n");
	printf("Высота дерева: %d\n", height(V)-1); // могу единицу вычесть, если надо, если вы корень за ноль считаете...
	printf("Колличество листиков: %d\n", list_count(V));
	printf("Нерекурсивный обход: ");
	iterPreorder(V);
	printf("\n");
	DelTree(&V);

}
