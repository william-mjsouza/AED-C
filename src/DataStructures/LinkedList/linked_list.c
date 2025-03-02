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
        printf("Erro ao alocar mem�ria para um novo n�!\n");
    }
}

void inserAtEnd(Node** head, int data) {
    // Aloca dinamicamente mem�ria sufiente para um n�
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        // Popula os campos do n�
        newNode->data = data;
        //newNode->next = ?
        if (*head == NULL) {
            // Cai no caso de inserir no in�cio
            newNode->next = *head;
            *head = newNode;    // Marca o novo n� como a nova cabe�a
        }
        else {
            // Percorre a lista da cabe�a at� o �ltimo n� usando um ponteiro tempor�rio temp
            Node* temp = *head; // Come�a a percorrer pela cabe�a
            while (temp->next != NULL) {
                temp = temp->next;  // Enquanto houver um pr�ximo avan�a um n�
            }
            newNode->next = temp->next; // newNode->next = NULL (�ltimo n� deve apontar para NULL)
            temp->next = newNode;   // O antigo �ltimo agora aponta pro novo �ltimo n� da lista
        }
    }
    else {
        // Trata erros de aloca��o
        printf("Erro ao alocar mem�ria para um novo n�!\n");
    }
}

void insertAfterValue(Node** head, int data, int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        // Popula os campos do novo n�
        newNode->data = data;
        if (*head == NULL) {
            printf("Erro: O valor %d ainda n�o existe na lista!\n", value);
            free(newNode);
            return;
        }
        else {
            // Percorre a lista com o ponteiro tempor�rio temp at� parar no n� do valor
            Node* temp = *head; // Come�a a percorrer pela cabe�a
            while (temp != NULL && temp->data != value) {
                temp = temp->next;
            }
            if (temp != NULL) {
                newNode->next = temp->next; // Faz novo n� ter o mesmo pr�ximo que o n� do valor
                temp->next = newNode;   // Agora o n� do valor aponta pro novo n�
            }
            else {
                // Trata o erro de percorrer toda a lista e n�o encontrar o valor
                printf("Erro: O valor %d ainda n�o existe na lista!\n", value);
                free(newNode);
            }
        }
    }
    else {
        // Trata erros de aloca��o
        printf("Erro ao alocar mem�ria para um novo n�!\n");
    }
}

void removeValue(Node** head, int value) {
    if (*head == NULL) {
        // Trata o erro de remover numa lista vazia
        printf("Erro: A lista est� vazia!\n");
        return;
    }
    else {
        // Cria um ponteiro remove para marcar o n� que ser� removido e um ponteiro tempor�rio temp para percorrer a lista
        Node* remove = NULL;
        Node* temp = *head; // Come�a a percorrer pela cabe�a
        
        if ((*head)->data == value) {
            // Trata o erro de remover a cabe�a
            *head = temp->next;
            free(temp);
            return;
        }

        // Enquanto houver um pr�ximo e o valor desse pr�ximo n�o for o valor informado
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;  // Avan�a um n�
        }
        // Agora temp aponta pro n� anterior ao que ser� removido ou para NULL se n�o achou o valor
        if (temp->next == NULL) {
            // Trata o erro de n�o ter achado o valor
            printf("Erro: O valor %d n�o existe na lista!\n", value);
        }
        else {
            remove = temp->next;
            temp->next = remove->next;
            free(remove);
        }
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

int linkedListLength(Node** head) {
    if (*head == NULL) {
        return 0;   // A lista n�o possui nenhum n�
    }
    else {
        // Percorre a lista com um ponteiro tempor�rio temp at� chegar em NULL
        Node* temp = *head; // Come�a a percorrer pela cabe�a
        int length = 0;
        while (temp != NULL) {
            temp = temp->next;  // Avan�a um n�
            length++;
        }
        return length;  // Retorna o tamanho da lista
    }
}