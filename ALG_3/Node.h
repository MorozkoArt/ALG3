#pragma once
typedef struct Node
{
	int info;
	Node* left;
	Node* right;
}Node;

Node* New(int data);
Node* Add(Node* v, int data);
void Print(Node* v);
void Pre_order(Node* v);
void In_order(Node* v);
void Post_order(Node* v);
int height(Node* v);
int list_count(Node* v);
void iterPreorder(Node* v);
void DelTree(Node** v);