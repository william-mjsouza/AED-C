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
        printf("Erro ao alocar memória para um novo nó!\n");
    }
}

void inserAtEnd(Node** head, int data) {
    // Aloca dinamicamente memória sufiente para um nó
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        // Popula os campos do nó
        newNode->data = data;
        //newNode->next = ?
        if (*head == NULL) {
            // Cai no caso de inserir no início
            newNode->next = *head;
            *head = newNode;    // Marca o novo nó como a nova cabeça
        }
        else {
            // Percorre a lista da cabeça até o último nó usando um ponteiro temporário temp
            Node* temp = *head; // Começa a percorrer pela cabeça
            while (temp->next != NULL) {
                temp = temp->next;  // Enquanto houver um próximo avança um nó
            }
            newNode->next = temp->next; // newNode->next = NULL (último nó deve apontar para NULL)
            temp->next = newNode;   // O antigo último agora aponta pro novo último nó da lista
        }
    }
    else {
        // Trata erros de alocação
        printf("Erro ao alocar memória para um novo nó!\n");
    }
}

void insertAfterValue(Node** head, int data, int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        // Popula os campos do novo nó
        newNode->data = data;
        if (*head == NULL) {
            printf("Erro: O valor %d ainda não existe na lista!\n", value);
            free(newNode);
            return;
        }
        else {
            // Percorre a lista com o ponteiro temporário temp até parar no nó do valor
            Node* temp = *head; // Começa a percorrer pela cabeça
            while (temp != NULL && temp->data != value) {
                temp = temp->next;
            }
            if (temp != NULL) {
                newNode->next = temp->next; // Faz novo nó ter o mesmo próximo que o nó do valor
                temp->next = newNode;   // Agora o nó do valor aponta pro novo nó
            }
            else {
                // Trata o erro de percorrer toda a lista e não encontrar o valor
                printf("Erro: O valor %d ainda não existe na lista!\n", value);
                free(newNode);
            }
        }
    }
    else {
        // Trata erros de alocação
        printf("Erro ao alocar memória para um novo nó!\n");
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