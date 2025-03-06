#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(Node** top, char* data) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Erro: Não foi possível alocar memória para um novo nó!\n");
	}
	else {
		newNode->data = data;
		newNode->next = *top;
		*top = newNode;
	}
}

void print(Node** top) {
	if (*top == NULL) {
		printf("Pilha = Vazia\n");
	}
	else {
		Node* temp = *top;
		printf("Pilha = \n");
		while (temp != NULL) {
			printf("        %s\n", temp->data);
			printf("        |\n");
			printf("        v\n");
			temp = temp->next;
		}
		printf("        NULL\n");
	}
}