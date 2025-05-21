#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

int main() {
	// Incializa a árvore binária de busca vazia
	TreeNode* root = NULL;

	// Insere valores na árvore
	insert(&root, 30);
	insert(&root, 45);
	insert(&root, 21);
	insert(&root, 14);

	// Exibe a árvore em pré-ordem
	preorder(root);
	printf("\n");
	// Exibe a árvore em ordem
	inorder(root);
	printf("\n");
	// Exibe a árvore em pós-ordem
	postorder(root);
	printf("\n");

	return 0;
}