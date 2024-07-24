#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
	size_t valor;
	struct item *proximo;
};

struct pilha {
	struct item *topo;
	int tamanho;
};

// Recebe inteiro, aloca memoria para um item, atribui o valor e retorna o item
struct item *criaItem(size_t valor);

// Aloca memoria para uma pilha e atribui o ponteiro topo para NULO
struct pilha *inicializaPilha();

// Retorna true para pilha vazia e false para pilha com ao menos um item
bool pilhaVazia(struct pilha *p);

// Dada uma pilha P, insere item com valor x chamado criaItem no topo da pilha; 
// retorna 1 se x foi inserido com sucesso, 0 se x não foi inserido.
int push(struct pilha *p, size_t x);

// Dada uma pilha P, remove elemento do topo, caso a pilha não esteja vazia; 
// retorna 1 se o elemento foi removido ou 0 se o elemento não foi removido.
// O ponteiro para inteiro 'dado' retorna o valor do topo...
// dado = NULL indica que usuário não quer guardar valor
int pop(struct pilha *p, size_t *dado);

// Destroi cada item da pilha (se não vazia) e destroi a pilha
void destroiPilha(struct pilha *p);