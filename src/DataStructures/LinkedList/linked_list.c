#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h> // Biblioteca para incluir as funções de alocação dinâmica de memória (malloc)

// Definição da função
void insertAtBeggining(Node** head, int data) {
    // Aloca dinamicamente memória suficiente para um novo nó e guarda seu endereço em newNode
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        // Popula os compos do novo nó
        newNode->data = data;
        newNode->next = *head; // Faz o novo nó apontar também pro que a cabeça atual está apontando

        *head = newNode; // Atualiza a cabeça da lista para o novo nó
    }
    else {
        // Trata erros de alocação
        printf("Erro ao alocar memória para um novo nó!");
    }
}

void printLinkedList(Node** head) {
    if (*head != NULL) {
        // Percorre toda a lista com um ponteiro temporário
        Node* temp = *head; // Inicia pela cabeça
        printf("Lista = ");
        while (temp->next != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;   // Avança pro próximo enquanto tiver um próximo
        }
        printf("%d -> NULL\n", temp->data); // O último nó da lista aponta para NULL
    }
    else {
        printf("Lista = vazia!\n");
    }
}