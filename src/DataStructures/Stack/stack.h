#ifndef STACK_H
#define STACK_H

// Molde de um nó para dados textuais
typedef struct Node {
    char* data;
    struct Node* next;
}Node;

// Protótipos:

// Função responsável por criar um novo nó e inserí-lo no topo da pilha (empilhar)
void push(Node** top, char* data);

// Função responsável por remover o nó do topo da pilha (desempilhar) e retorná-lo para main
Node* pop(Node** top);

// Função responsável por percorrer toda a pilha exibindo cada nó
void print(Node** top);

// Função responsável por retornar a quantidade de nós na pilha
int size(Node** top);

#endif // STACK_H
