#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Molde de um n� para caracteres
typedef struct Node{
	char data;
	struct Node* next;
} Node;

// Fun��o respons�vel por criar um n� e inser�-lo no final da lista encadeada
void insertAtAnd(Node** head, char data);

// Fun��o respons�vel por exibir a lista encadeada
void printList(Node** head);

// Fun��o respons�vel por trocar 2 n�s na lista encadeada
void swapNodes(Node** head, char value1, char value2);

#endif // LINKED_LIST_H
