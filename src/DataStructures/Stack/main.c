#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	// Inicia a pilha vazia
	Node* top = NULL;

	// Empilha os comandos
	push(&top, "Comando 1");
	push(&top, "Comando 2");
	push(&top, "Comando 3");

	// Exibe a pilha
	print(&top);

	// Desempilha os comandos
	Node* temp = pop(&top);
	printf("Nó removido = %s\n", temp->data);
	free(temp);	// Libera a memória após o seu uso
	print(&top);

	printf("A pilha possui %d nós.\n", size(&top));

	return 0;
}