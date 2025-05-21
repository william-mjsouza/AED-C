#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

// Função para inserir um novo nó na árvore binária de busca
void insert(TreeNode** root, int data);

// Função para exibir a árvore binária de busca em pré-ordem
void preorder(TreeNode* root);

// Função para exibir a árvore binária de busca em ordem
void inorder(TreeNode* root);

// Função para exibir a árvore em pós-ordem
void postorder(TreeNode* root);

#endif // BINARY_SEARCH_TREE_H
