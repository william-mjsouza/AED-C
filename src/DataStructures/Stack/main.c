#include <stdio.h>
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

	return 0;
}