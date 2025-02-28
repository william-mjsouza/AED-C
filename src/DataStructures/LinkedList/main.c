#include "linked_list.h"
#include <stdio.h>

int main() {
    // Inicia a lista vazia
    Node* head = NULL;
    printLinkedList(&head); // Lista = Vazia

    // Insere elementos no início da lista
    insertAtBeggining(&head, 32);
    insertAtBeggining(&head, 64);
    insertAtBeggining(&head, 128);

    printLinkedList(&head); // Lista = 128 -> 64 -> 32 -> NULL

    return 0;
}
