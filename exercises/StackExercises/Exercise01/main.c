/*===================================================================================================
Um determinado programa será implementado em C e deve permitir manipular nomes de alunos em uma pilha
, implemente as seguintes funcionalidades para o programa:

a) Inserir novos elementos;

b) Imprimir a base da pilha;

c) Imprimir todos os nós na posição par.
===================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Student* top = NULL;

    // Insere novos alunos na pilha
    push(&top, "William");
    push(&top, "Leal");
    push(&top, "Messi");

    // Exibe a base da pilha
    printStackBase(&top);

    // Exibe os nós pares da pilha
    printPairPositionNodes(&top);

    return 0;
}
