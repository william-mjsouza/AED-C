#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Molde de um nó para caracteres
typedef struct Node{
	char data;
	struct Node* next;
} Node;

// Função responsável por criar um nó e inserí-lo no final da lista encadeada
void insertAtAnd(Node** head, char data);

// Função responsável por exibir a lista encadeada
void printList(Node** head);

// Função responsável por trocar 2 nós na lista encadeada
void swapNodes(Node** head, char value1, char value2);

#endif // LINKED_LIST_H
