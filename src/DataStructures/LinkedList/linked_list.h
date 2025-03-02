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

// Fun��o respons�vel por criar um novo n� e inser�-lo no final da lista
void inserAtEnd(Node** head, int data);

// Fun��o respons�vel por criar um novo n� e inser�-lo antes do valor informado
void insertAfterValue(Node** head, int data, int value);

// Fun��o respons�vel por remover da lista a primeira ocorr�ncia do n� que possui o valor informado
void removeValue(Node** head, int value);

// Fun��o respons�vel por exibir cada n� da lista encadeada
void printLinkedList(Node** head);

// Fun��o respons�vel por retornar o tamanho da lista
int linkedListLength(Node** head);

#endif // LINKED_LIST_H
