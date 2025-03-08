#ifndef QUEUE_H
#define QUEUE_H

// Molde de um nó de inteiros
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// Função responsável por criar um novo nó e inserí-lo no final da fila (enfileirar)
void enqueue(Node** head, Node** tail, int data);

// Funçãoresponsável por exibir a fila
void print(Node** head);

#endif	// QUEUE_H
