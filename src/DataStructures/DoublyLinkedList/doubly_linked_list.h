#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/**
 * @brief Estrutura que representa um nó de uma lista duplamente encadeada
 * 
 * Um nó armazena um dado (nesse caso, um inteiro) e conhece o próximo nó
 * e o nó anterior a ele.
 */
typedef struct Node {
	int data;			/**< Valor armazenado no nó */
	struct Node* next;	/**< Ponteiro pro próximo nó */
	struct Node* prev;	/**< Ponteiro pro nó anterior */
} Node;

// Protótipos:

/* ==========================================================================
 * Principais Operações
 * ========================================================================== */

/* ==========================================================================
 * Inserção
 * ========================================================================== */

/**
 * @brief Insere um novo nó no início da lista duplamente encadeada.
 * 
 * @param head Ponteiro para modificar o ponteiro que marca o 1º nó da lista.
 * @param data Dado (nesse caso, um inteiro) que será armazenado no nó.
 * @return void
 */
void insertAtBeginning(Node** head, int data);

/**
 * @brief Insere um novo nó no final da lista duplamente encadeada.
 * 
 * @param head Ponteiro para modificar o ponteiro que marca o 1º nó da lista.
 * @param data Dado (nesse caso, um inteiro) que será armazenado no nó.
 * @return void
 */
void insertAtEnd(Node** head, int data);

/* ==========================================================================
 * Remoção
 * ========================================================================== */

/**
 * @brief Remove o primeiro nó da lista duplamente encadeada.
 * 
 * @param head Ponteiro para modificar o ponteiro que marca o 1º nó da lista.
 * @return Node* Nó que foi desconectado da lista.
 */
Node* removeAtBeginning(Node** head);

/**
 * @brief Remove o último nó da lista duplamente encadeada.
 * 
 * @param head Ponteiro para modificar o ponteiro que marca o 1° nó da lista.
 * @return Node* Nó que foi desconectado da lista.
 */
Node* removeAtEnd(Node** head);

/* ==========================================================================
 * Operações Úteis
 * ========================================================================== */

/**
 * @brief Exibe a lista duplamente encadeada.
 * 
 * @param head Ponteiro para modificar o ponteiro que marca o 1º nó da lista.
 * @return void
 */
void print(Node** head);

#endif // DOUBLY_LINKED_LIST_H
