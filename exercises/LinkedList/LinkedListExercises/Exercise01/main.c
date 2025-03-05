/*
Fa�a uma fun��o que troque o n� A com o n� F.
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

    // Troca o n� a pelo n� F
    swapNodes(&head, 'A', 'F');
    printList(&head);

    return 0;
}
