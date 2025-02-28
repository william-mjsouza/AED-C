#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h> // Biblioteca para incluir as fun��es de aloca��o din�mica de mem�ria (malloc)

// Defini��o da fun��o
void insertAtBeggining(Node** head, int data) {
    // Aloca dinamicamente mem�ria suficiente para um novo n� e guarda seu endere�o em newNode
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        // Popula os compos do novo n�
        newNode->data = data;
        newNode->next = *head; // Faz o novo n� apontar tamb�m pro que a cabe�a atual est� apontando

        *head = newNode; // Atualiza a cabe�a da lista para o novo n�
    }
    else {
        // Trata erros de aloca��o
        printf("Erro ao alocar mem�ria para um novo n�!");
    }
}

void printLinkedList(Node** head) {
    if (*head != NULL) {
        // Percorre toda a lista com um ponteiro tempor�rio
        Node* temp = *head; // Inicia pela cabe�a
        printf("Lista = ");
        while (temp->next != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;   // Avan�a pro pr�ximo enquanto tiver um pr�ximo
        }
        printf("%d -> NULL\n", temp->data); // O �ltimo n� da lista aponta para NULL
    }
    else {
        printf("Lista = vazia!\n");
    }
}