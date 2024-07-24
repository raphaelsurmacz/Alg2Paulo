#include "pilha.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Recebe inteiro, aloca memoria para um item, atribui o valor e retorna o item
struct item *criaItem(size_t valor) {
	struct item *node = malloc(sizeof(struct item));
	if (!node) {
		return NULL;
	}
	node->valor = valor;
	node->proximo = NULL;
	return node;
}

// Aloca memoria para uma pilha e atribui o ponteiro topo para NULO
struct pilha *inicializaPilha() {
	struct pilha *pilha = (struct pilha*)malloc(sizeof(struct pilha));
	if (!pilha) {
		return NULL;
	}
	pilha->topo = NULL;
	pilha->tamanho = 0;
	return pilha;
}

// Retorna true para pilha vazia e false para pilha com ao menos um item
bool pilhaVazia(struct pilha *p) {
    if (p->topo == 0) {
        return true; // pilha vazia
    }
    return false; // pilha com ao menos um itemP
}

// Dada uma pilha insere item com valor x chamando criaItem no topo da pilha; 
// retorna 1 se x foi inserido com sucesso, 0 se x não foi inserido.
int push(struct pilha *p, size_t x) {
	// criar novo item (se não conseguir, retorne 0)
	struct item *novo = criaItem(x);
	if (!novo) {
		return 0;
	}
	// próximo do novo é antigo topo, e novo topo aponta pra novo
	novo->proximo = p->topo;
	p->topo = novo;

	// item foi adicionado com sucesso (tamanho aumentou)
	p->tamanho++;	
	return 1;
}

// Dada uma pilha P, remove elemento do topo, caso a pilha não esteja vazia; 
// retorna 1 se o elemento foi removido ou 0 se o elemento não foi removido.
// O ponteiro para inteiro 'dado' retorna o valor do topo...
// dado = NULL indica que usuário não quer guardar valor
int pop(struct pilha *p, size_t *dado) {
	// se pilha estiver vazia, não tem como remover
	if (pilhaVazia(p)) {
		return 0;
	}
	// dado recebe valor do topo
	if (dado) {
		*dado = p->topo->valor;
	}
	// topo vira próximo e libera antigo topo
	struct item *temp = p->topo;
	p->topo = p->topo->proximo;
	free(temp);

	// item deletado com sucesso (tamanho diminuiu)
	p->tamanho--;
	return 1;
}

// Destroi cada item da pilha (se não vazia) e destroi a pilha
void destroiPilha(struct pilha *p) {
	while (!pilhaVazia(p)) {
		pop(p, NULL);
	}
	free(p);
	return;
}