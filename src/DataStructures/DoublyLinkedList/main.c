#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
    // Inicia a lista duplamente encadeada vazia
    Node* head = NULL;              // -> NULL

    // Insere os valores nela
    insertAtBeginning(&head, 42);   // 42 -> NULL
    insertAtBeginning(&head, 50);   // 50 -> 42 -> NULL
    insertAtEnd(&head, 74);         // 50 -> 42 -> 74 -> NULL

    // Exibe a lista
    print(&head);                   // 50 -> 42 -> 74 -> NULL

    return 0;
}
