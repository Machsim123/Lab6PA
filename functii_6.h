#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char type;
	int num;
	struct Node *right, *left;
}Node;

Node* createNode();

Node* createTree();

void afisare();

void numarare_grupulete();

void afisare_grupulete();
