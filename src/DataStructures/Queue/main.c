#include <stdio.h>
#include "queue.h"

int main() {
    // Inicia  fila vazia
    Node* head = NULL;
    Node* tail = NULL;
    
    // Enfileira dados na final
    enqueue(&head, &tail, 32);
    enqueue(&head, &tail, 40);
    enqueue(&head, &tail, 57);

    // Exibe a fila
    print(&head);
    
    return 0;
}
