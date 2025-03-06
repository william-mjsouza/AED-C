#ifndef STACK_H
#define STACK_H

// Molde de um nó de alunos
typedef struct Student {
    char name[30];
    struct Student* next;
}  Student;

// Protótipos:

// Função responsável por criar e inserir um nó no topo da pilha (empilhar)
void push(Student** top, char name[30]);

// Função responsável por exibir a base da pilha
void printStackBase(Student** top);

void printPairPositionNodes(Student** top);

#endif // STACK_H
