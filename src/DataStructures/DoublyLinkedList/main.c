#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    // Inicia a lista duplamente encadeada vazia
    Node* head = NULL;                          // -> NULL

    // Insere os valores nela
    insertAtBeginning(&head, 42);               // 42 -> NULL
    insertAtBeginning(&head, 50);               // 50 -> 42 -> NULL
    insertAtEnd(&head, 74);                     // 50 -> 42 -> 74 -> NULL

    // Exibe a lista
    print(&head);                               // 50 -> 42 -> 74 -> NULL

    // Remove os nós dela
    Node* remove = removeAtBeginning(&head);    // 42 -> 74 -> NULL
    if (remove != NULL) free(remove);
    remove = removeAtEnd(&head);                // 42 -> NULL
    if (remove != NULL) free(remove);

    // Exibe a lista
    print(&head);                               // 42 -> NULL


    return 0;
}
