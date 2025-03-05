/*
Faça uma função que troque o nó A com o nó F.
*/

#include "linked_list.h">
#include <stdio.h>

int main() {
    // Inicia a lista vazia
    Node* head = NULL;

    // Adiciona no final da lista
    insertAtAnd(&head, 'B');
    insertAtAnd(&head, 'A');
    insertAtAnd(&head, 'C');
    insertAtAnd(&head, 'D');
    insertAtAnd(&head, 'F');
    insertAtAnd(&head, 'G');

    // Exibe a lista
    printList(&head);

    // Troca o nó a pelo nó F
    swapNodes(&head, 'A', 'F');
    printList(&head);

    return 0;
}
