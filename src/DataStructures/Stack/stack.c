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

Node* pop(Node** top) {
	if (*top == NULL) {
		printf("A lista está vazia!\n");
	}
	else {
		Node* remove = *top;
		*top = remove->next;
		return remove;
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
		printf("        NULL\n\n");
	}
}

int size(Node** top) {
	if (*top == NULL) {
		return 0;
	}
	else {
		Node* temp = *top;
		int i = 0;
		while (temp != NULL) {
			i++;
			temp = temp->next;
		}
		return i;
	}
}