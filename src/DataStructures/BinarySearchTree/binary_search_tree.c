#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void insert(TreeNode** root, int data) {
	if (*root == NULL) {
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		if (newNode == NULL) {
			printf("Erro: Não foi possível alocar um nó!\n");
			return;
		}

		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		*root = newNode;
	}
	else {
		if (data < (*root)->data) {
			insert(&((*root)->left), data);
		}
		else {
			insert(&((*root)->right), data);
		}
	}
}

// NLR
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);	// N
		preorder(root->left);		// L
		preorder(root->right);		// R
	}
}

// LNR
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);		// L
		printf("%d ", root->data);	// N
		inorder(root->right);		// R
	}
}

// LRN
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);		// L
		postorder(root->right);		// R
		printf("%d ", root->data);	// N
	}
}
