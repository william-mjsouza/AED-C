#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Molde de um nó para dados inteiros
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Protótipos:

// Função responsável por criar um novo nó e adicioná-lo no início da lista (nó = cabeça da lista)
void insertAtBeggining(Node** head, int data);

// Função responsável por exibir cada nó da lista encadeada
void printLinkedList(Node** head);

#endif // LINKED_LIST_H
