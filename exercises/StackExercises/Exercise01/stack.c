#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

// Definição das funções:

void push(Student** top, char name[30]) {
	Student* newStudent = (Student *)malloc(sizeof(Student));
	if (newStudent == NULL) {
		printf("Erro: Não foi possível alocar memória para um novo aluno!\n");
	}
	else{
		strcpy(newStudent->name, name);
		newStudent->next = *top;
		*top = newStudent;
	}
}

void printStackBase(Student** top) {
	if (*top == NULL) {
		printf("Pilha = Vazia\n");
	}
	else {
		Student* temp = *top;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		printf("Base da pilha = %s\n", temp->name);
	}
}

void printPairPositionNodes(Student** top) {
	if (*top == NULL) {
		printf("Pilha = Vazia\n");
	}
	else {
		Student* temp = *top;
		int i = 0;
		while (temp != NULL) {
			if (i % 2 == 0) {
				printf("Nó[%d] = %s\n", i, temp->name);
			}
			i++;
			temp = temp->next;
		}
	}
}