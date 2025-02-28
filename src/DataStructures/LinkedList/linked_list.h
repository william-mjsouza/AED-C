#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Molde de um n� para dados inteiros
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Prot�tipos:

// Fun��o respons�vel por criar um novo n� e adicion�-lo no in�cio da lista (n� = cabe�a da lista)
void insertAtBeggining(Node** head, int data);

// Fun��o respons�vel por exibir cada n� da lista encadeada
void printLinkedList(Node** head);

#endif // LINKED_LIST_H
