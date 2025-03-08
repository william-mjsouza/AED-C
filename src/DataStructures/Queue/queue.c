#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Node** head, Node** tail, int data) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Erro: Não foi possível alocar memória para um novo nó!\n");
	}
	else {
		newNode->data = data;
		if (*head == NULL) {
			newNode->next = *head;
			*head = newNode;
			*tail = newNode;
		}
		else {
			newNode->next = (*tail)->next; // newNode->next = NULL
			(*tail)->next = newNode;
		}
	}
}

void print(Node** head) {
	if (*head == NULL) {
		printf("Fila = Vazia\n");
	}
	else {
		Node* temp = *head;
		printf("Fila = ");
		while (temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}