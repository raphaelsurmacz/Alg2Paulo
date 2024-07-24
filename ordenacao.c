#include "ordenacao.h"

#include "pilha.h"

// Adição de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Elen Pasqualli Gesser", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20213400; }

//----------------------------------------------------Funções auxiliares
// Função que imprime na tela os elementos dentro do vetor
void imprimeVetor(int *vetor, size_t tam) {
	return;
	for (int i = 0; i < tam; i++)
		printf("[%d] ", *(vetor + i));
	printf("\n");
}

// Função que preenche o vetor aleatoriamente
void preencheVetor(int *vetor, size_t tam) {
	for (int i = 0; i < tam; ++i) {
		*(vetor + i) = tam - i;
		//*(vetor + i) = rand() % 99;
    }
}

// Função auxiliar das ordenações que troca 2 elementos dentro do vetor
int trocar(int *vetor, size_t idxIni, size_t tam) {
	size_t aux = *(vetor + idxIni);
	*(vetor + idxIni) = *(vetor + tam);
	*(vetor + tam) = aux;

	return *vetor;
}

//----------------------------------------------------MERGE SORT REC
void copiar(int *vetor, int *vetorAux, size_t idxIni, size_t tam) {
    for (size_t i = 0; i < tam; ++i) {
        vetor[idxIni + i] = vetorAux[i];
    }
}

void merge(int *vetor, int *vetorAux, size_t idxIni, size_t meio, size_t tam, uint64_t *mergeComp) {
	size_t k = 0;
	size_t i = idxIni;
	size_t j = meio + 1;
	size_t idxAux;

	while (k <= tam-idxIni) {
		if (j>tam || (i<=meio && vetor[i]<=vetor[j])) {
			*mergeComp += 1;
			idxAux = i;
			i++;

		} else {

			*mergeComp += 1;
			idxAux =j;
			j++;
		}
		vetorAux[k] = vetor[idxAux];
		k++;
	}

    copiar(vetor, vetorAux, idxIni, tam - idxIni + 1);
}

void auxMergeSort(int *vetor, int *vetorAux, size_t idxIni, size_t tam, uint64_t *mergeComp) {
	if (idxIni < tam) {
		size_t meio = (idxIni + tam) / 2;

		auxMergeSort(vetor,vetorAux, idxIni, meio, mergeComp);
		auxMergeSort(vetor, vetorAux, meio+1, tam, mergeComp);

		merge(vetor, vetorAux, idxIni, meio, tam, mergeComp);
	}
}

uint64_t mergeSort(int vetor[], size_t tam) {
	size_t idxIni = 0;
	uint64_t mergeComp = 0;

	int *vetorAux = (int*)malloc(tam * sizeof(int));
	if (vetorAux == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	auxMergeSort(vetor, vetorAux, idxIni, tam-1, &mergeComp);

	free(vetorAux);

	return mergeComp;
}

//----------------------------------------------------QUICK SORT REC
int particionaVetor(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp) {
	size_t pivo = *(vetor+tam);
	size_t idxAux = idxIni;

	for (size_t i = idxIni; i < tam; ++i) {
		if (*(vetor + i) <= pivo) {
			(*quickComp += 1);
			trocar(vetor, idxAux, i);
			idxAux++;
		}

		//*quickComp += 1;
	}
		
	trocar(vetor, idxAux, tam);
	return idxAux;
}

void auxQuickSort(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp) {
	if (idxIni < tam) {
		size_t meio = particionaVetor(vetor, idxIni, tam, quickComp);

		if (meio > 0) {
			auxQuickSort(vetor, idxIni, meio-1, quickComp);
		}
		auxQuickSort(vetor, meio+1, tam, quickComp);
	}
}

uint64_t quickSort(int vetor[], size_t tam) {
	size_t idxIni = 0;
	uint64_t quickComp = 0;
	
	auxQuickSort(vetor, idxIni, tam-1, &quickComp);

	return quickComp;
}

//----------------------------------------------------HEAP SORT REC
void maxHeapfy(int *vetor, size_t i, size_t tam, uint64_t *heapComp) {
	size_t fEsquerdo = 2*i+1;
	size_t fDireito = 2*i+2;
	size_t maior = i;
	
	if (fEsquerdo < tam && *(vetor+fEsquerdo) > *(vetor+maior)) {
		*heapComp += 1;
		maior = fEsquerdo;
	} 

	if (fDireito < tam && *(vetor+fDireito) > *(vetor+maior)) {
		*heapComp += 1;
		maior = fDireito;
	}

	if (maior != i) {
		trocar(vetor, i, maior);
		maxHeapfy(vetor, maior, tam, heapComp);
	}
}

void fazerMaxHeap(int *vetor, size_t tam, uint64_t *heapComp) {
	for (int i = (tam/2)-1; i >= 0; i--) {
		maxHeapfy(vetor, i, tam, heapComp);
    }
}

void auxHeapSort(int *vetor, size_t tam, uint64_t *heapComp) {

	fazerMaxHeap(vetor, tam, heapComp);

	for (int i = tam-1; i > 0; --i) {
		trocar(vetor, 0, i);
		maxHeapfy(vetor, 0, i, heapComp);
	}
}

uint64_t heapSort(int vetor[], size_t tam) {
    uint64_t heapComp = 0;

    auxHeapSort(vetor, tam, &heapComp);

	return heapComp;
}

//----------------------------------------------------MERGE SORT SEM RECURSÃO
// Função que acha o menor número entre dois número
size_t min(size_t x, size_t y) {
	if (x < y) {
		return x;
	} else {
		return y;
	}
}

void auxMergeSortRS(int *vetor, int *vetorAux, size_t tam, uint64_t *mergeComp) {
	size_t tamAtual;                 
   	size_t iniIni;

	for (tamAtual = 1; tamAtual <= tam-1; tamAtual = 2*tamAtual) {
        for (iniIni = 0; iniIni < tam-1; iniIni += 2*tamAtual) {
           size_t meio = min(iniIni + tamAtual - 1, tam-1);
           size_t idxFim = min(iniIni + 2*tamAtual - 1, tam-1);

           merge(vetor, vetorAux, iniIni, meio, idxFim, mergeComp);
        }
    }
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    uint64_t mergeComp = 0;

    int *vetorAux = (int*)malloc(tam * sizeof(int));
    if (vetorAux == NULL) {
        printf("Falha fatal. Impossível alocar memória.\n");
        return 1;
    }

    auxMergeSortRS(vetor, vetorAux, tam, &mergeComp);

    free(vetorAux);

    return mergeComp;
}

//----------------------------------------------------QUICK SORT SEM RECURSÃO
void auxQuickSortSR(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp) {
	// Utilização do uso de bibliotexa de pilha para a retirada da recusão
	size_t meio;
	struct pilha *p = inicializaPilha();
	push(p, idxIni);
	push(p, tam);

	while (!pilhaVazia(p)) {
		pop(p, &tam);
		pop(p, &idxIni);

		if (idxIni < tam) {
			meio = particionaVetor(vetor, idxIni, tam, quickComp);
			push(p, idxIni);
			push(p, meio-1);
			push(p, meio+1);
			push(p, tam);
		}
	}

	destroiPilha(p);
}

uint64_t quickSortSR(int vetor[], size_t tam) {
	size_t idxIni = 0;
	uint64_t quickComp = 0;
	
	auxQuickSort(vetor, idxIni, tam-1, &quickComp);

	return quickComp;
}

//----------------------------------------------------HEAP SORT SEM RECURSÃO
void maxHeapfySR(int *vetor, size_t i, size_t tam, uint64_t *heapComp) {
	size_t fEsquerdo = 2*i+1;
	size_t fDireito = 2*i+2;
	size_t maior = i;
	
	while (fEsquerdo < tam) {
		if (fEsquerdo < tam && *(vetor+fEsquerdo) > *(vetor+maior)) {
			*heapComp += 1;
			maior = fEsquerdo;
		} 

		if (fDireito < tam && *(vetor+fDireito) > *(vetor+maior)) {
			*heapComp += 1;
			maior = fDireito;
		}

		// Condições para remoção da recurssão
		if (maior != i) {
			trocar(vetor, i, maior);
			i = maior;
			fEsquerdo = 2*i+1;
			fDireito = 2*i+2;

		} else {
			break; 
		}
	}
}

void auxHeapSortSR(int *vetor, size_t tam, uint64_t *heapComp) {

	fazerMaxHeap(vetor, tam, heapComp);

	for (int i = tam-1; i > 0; --i) {
		trocar(vetor, 0, i);
		maxHeapfySR(vetor, 0, i, heapComp);
	}
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    uint64_t heapComp = 0;

    auxHeapSortSR(vetor, tam, &heapComp);

	return heapComp;
}