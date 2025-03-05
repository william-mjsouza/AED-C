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

    inserAtEnd(&head, 40);
    inserAtEnd(&head, 80);
    printLinkedList(&head); // Lista = 128 -> 64 -> 32 -> 40 -> 80 -> NULL

    insertAfterValue(&head, 10, 40);
    printLinkedList(&head); // Lista = 128 -> 64 -> 32 -> 40 -> 10 -> 80 -> NULL

    removeValue(&head, 64);
    printLinkedList(&head); // Lista = 128 -> 32 -> 40 -> 10 -> 80 -> NULL

    printf("A lista possui %d elementos.\n", linkedListLength(&head)); // 5

    return 0;
}
