#include "linked_list.h">
#include <stdio.h>
#include <stdlib.h>	// Para poder usar o malloc()

void insertAtAnd(Node** head, int data) {
	// Aloca dinamicamente memória suficiente para um novo nó
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode) {
		// Popula os campos do novo nó
		newNode->data = data;
		// newNode->next = ? (depende se a lista está vazia ou não)
		if (*head == NULL) {
			// Trata a situação da lista estar vazia (cai no caso de inserir no início)
			newNode->next = *head;	// Novo nó passa a pontar pro que a cabeça estiver apontando
			*head = newNode;	// Novo nó se torna a nova cabeça
		}
		else {
			// Percorre a lista com o ponteiro temporário temp até chegar no último nó
			Node* temp = *head;	// Começa a percorrer pela cabeça
			while (temp->next != NULL) {
				temp = temp->next;	// Enquanto houver um próximo, avança um nó
			}
			// Agora temp está apontando pro último nó
			newNode->next = temp->next;	// newNode->next = NULL (último nó sempre aponta pra NULL)
			temp->next = newNode;	// agora o antigo último passa a apontar para o novo último nó
		}
	}
	else {
		// Trata o erro de não conseguir alocar memória
		printf("Erro: Não foi possível alocar memória para um novo nó!\n");
	}
}

void printList(Node** head) {
	if (*head == NULL) {
		// Trata o caso da lista estar vazia
		printf("Lista = Vazia\n");
	}
	else {
		// Percorre a lista da cabeça até o final
		Node* temp = *head;
		printf("Lista = ");
		while (temp != NULL) {
			printf("%c -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void swapNodes(Node** head, char valueA, char valueF) {
	if (*head == NULL || valueA == valueF) {
		printf("Lista vazia ou valores iguais. Nenhuma troca feita.\n");
		return;
	}

	Node* prevA = NULL, * prevF = NULL;
	Node* nodeA = *head, * nodeF = *head;

	// Encontrar os nós A e F e seus nós anteriores
	while (nodeA && nodeA->data != valueA) {
		prevA = nodeA;
		nodeA = nodeA->next;
	}
	while (nodeF && nodeF->data != valueF) {
		prevF = nodeF;
		nodeF = nodeF->next;
	}

	// Verificar se ambos os nós foram encontrados
	if (nodeA == NULL || nodeF == NULL) {
		printf("Um dos nós não foi encontrado. Nenhuma troca feita.\n");
		return;
	}

	// Se A ou F forem a cabeça da lista, precisamos atualizar *head
	if (prevA != NULL)
		prevA->next = nodeF;
	else
		*head = nodeF;

	if (prevF != NULL)
		prevF->next = nodeA;
	else
		*head = nodeA;

	// Troca os ponteiros `next`
	Node* temp = nodeA->next;
	nodeA->next = nodeF->next;
	nodeF->next = temp;
}