#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void insertAtBeginning(Node** head, int data) {
	/*
	 * Aloca dinamicamente um nó e trata possível erro de alocação.
	 */
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Erro: Não foi possível alocar memória para um nó!\n");
		return;
	}

	/*
	 * Dado que o nó foi alocado, popula os campos dele:
	 * 1º - Armazena o dado nele.
	 * 2º - Como queremos inserir no início, o próximo do nó deve marcar o que head está apontando
	 *		(primeiro vira segundo).
	 * 5º - E atualizar o head para marcar o nó com ele (define a nova cabeça).
	 * 3º - O anterior do nó deve ser NULL, pois ele será a nova cabeça e não deve ter nada antes 
	 *      dela.
	 * 4º - Mas antes de atualizar o head, deve-se atualizar o prev dele, se a lista não estiver 
	 *		vazia (se tiver pelo menos um nó nela), pois o nó é inserido antes dele.
	 */
	newNode->data = data;
	newNode->next = *head;
	newNode->prev = NULL;		 /**< Antes de head não tem nada */
	if (*head != NULL) {
		(*head)->prev = newNode; /**< Atualiza o prev do antigo head (tem um nó atrás dele) */
	}
	*head = newNode;		     /**< Agora o nó é o novo head */
}

void insertAtEnd(Node** head, int data) {
	/*
	 * Aloca dinamicamente um nó e trata possível erro de alocação.
	 */
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Erro: Não foi possível alocar memória para um nó!\n");
		return;
	}

	/*
	 * Dado que foi alocado, popula os campos dele:
	 * 1º - Armazena o dado nele.
	 * 2º - Faz o próximo do nó ser NULL (último nó sempre aponta para NULL). 
	 * 3º - Anterior do nó = ? (depende se a lista está vazia ou não). Se tiver vazia, cai no caso de
	 *		inserir no início. Mas caso não esteja vazia, deve-se percorrer a lista até chegar no 
	 *      atual último nó e atualizá-lo para que ele fique antes do nó (o próximo dele deve ser o 
	 *      nó e o anterior do nó deve ser ele).
	 */
	newNode->data = data;
	newNode->next = NULL;
	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;		/**< Atualiza o marcador da cabeça */
		return;
	}
	/*
	 * Uso de uma varável auxiliar temporária para percorrer a lista da cabeça até o atual último nó
	 * (após o laço, temp marcará o antigo último nó).
	 */
	Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

Node* removeAtBeginning(Node** head) {
	/*
	 * Se a lista estiver vazia, apenas avisa, pois não há o que remover.
	 */
	if (*head == NULL) {
		printf("A lista está vazia!\n");
		return NULL;
	}

	/*
	 * Mas se há pelo menos um nó na lista, deve-se atualizar o head:
	 * 1º - Marca o head para remoção.
	 * 2º - Atualiza o head (o segundo nó vira o primeiro).
	 * 3º - Atualiza o prev do novo head.
	 */
	Node* remove = *head;
	*head = (*head)->next;
	if (*head != NULL) {
		(*head)->prev = NULL;	/**< Desconecta da lista o antigo primeiro nó */
	}
	return remove;
}

Node* removeAtEnd(Node** head) {
	/*
	 * Se a lista estiver vazia, apenas avisa, pois não há o que remover.
	 */
	if (*head == NULL) {
		printf("A lista está vazia!\n");
		return NULL;
	}

	/**
	 * Mas se há pelo menos um nó na lista, deve-se chegar até o último nó da lista e atualizar
	 * os pomteiros do nó anterior a ele (se houver um anterior, esse penúltimo vira último):
	 */
	Node* remove = *head;
	while (remove->next != NULL) {
		remove = remove->next;
	}

	// Se tiver apenas 1 nó na lista
	if (remove->prev == NULL) {
		*head = NULL;							/**< Atualiza o head */
	}
	// Mas se tiver 2 ou mais nós na lista
	else {
		remove->prev->next = NULL;				/**> Atualiza o penúltimo nó */
	}
	return remove;
}

void print(Node** head) {
	/*
	 * Se a lista estiver vazia, apenas exibe a mensagem de aviso.
	 */
	if (*head == NULL) {
		printf("Lista = Vazia\n");
		return;
	}

	/*
	 * Dado que a lista não está vazia, ela é percorrida com um ponteiro auxiliar temporário temp 
	 * da cabeça até o último nó exibindo os dados armazenados em cada nó.
	 */
	Node* temp = *head;
	printf("Lista = ");
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
