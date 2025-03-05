#include "linked_list.h">
#include <stdio.h>
#include <stdlib.h>	// Para poder usar o malloc()

void insertAtAnd(Node** head, int data) {
	// Aloca dinamicamente mem�ria suficiente para um novo n�
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode) {
		// Popula os campos do novo n�
		newNode->data = data;
		// newNode->next = ? (depende se a lista est� vazia ou n�o)
		if (*head == NULL) {
			// Trata a situa��o da lista estar vazia (cai no caso de inserir no in�cio)
			newNode->next = *head;	// Novo n� passa a pontar pro que a cabe�a estiver apontando
			*head = newNode;	// Novo n� se torna a nova cabe�a
		}
		else {
			// Percorre a lista com o ponteiro tempor�rio temp at� chegar no �ltimo n�
			Node* temp = *head;	// Come�a a percorrer pela cabe�a
			while (temp->next != NULL) {
				temp = temp->next;	// Enquanto houver um pr�ximo, avan�a um n�
			}
			// Agora temp est� apontando pro �ltimo n�
			newNode->next = temp->next;	// newNode->next = NULL (�ltimo n� sempre aponta pra NULL)
			temp->next = newNode;	// agora o antigo �ltimo passa a apontar para o novo �ltimo n�
		}
	}
	else {
		// Trata o erro de n�o conseguir alocar mem�ria
		printf("Erro: N�o foi poss�vel alocar mem�ria para um novo n�!\n");
	}
}

void printList(Node** head) {
	if (*head == NULL) {
		// Trata o caso da lista estar vazia
		printf("Lista = Vazia\n");
	}
	else {
		// Percorre a lista da cabe�a at� o final
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

	// Encontrar os n�s A e F e seus n�s anteriores
	while (nodeA && nodeA->data != valueA) {
		prevA = nodeA;
		nodeA = nodeA->next;
	}
	while (nodeF && nodeF->data != valueF) {
		prevF = nodeF;
		nodeF = nodeF->next;
	}

	// Verificar se ambos os n�s foram encontrados
	if (nodeA == NULL || nodeF == NULL) {
		printf("Um dos n�s n�o foi encontrado. Nenhuma troca feita.\n");
		return;
	}

	// Se A ou F forem a cabe�a da lista, precisamos atualizar *head
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