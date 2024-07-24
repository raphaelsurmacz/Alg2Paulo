#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

//----------------------------------------------------Funções auxiliares
// Função que imprime na tela os elementos dentro do vetor
void imprimeVetor(int *vetor, size_t tam);

// Função que preenche o vetor aleatoriamente
void preencheVetor(int *vetor, size_t tam);

// Função auxiliar das ordenações que troca 2 elementos dentro do vetor
int trocar(int *vetor, size_t idxIni, size_t tam);

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

//----------------------------------------------------MERGE SORT REC
void copiar(int *vetor, int *vetorAux, size_t idxIni, size_t tam);
void merge(int *vetor, int *vetorAux, size_t idxIni, size_t meio, size_t tam, uint64_t *mergeComp);
void auxMergeSort(int *vetor, int vetorAux[], size_t idxIni, size_t tam, uint64_t *mergeComp);
uint64_t mergeSort(int vetor[], size_t tam);

//----------------------------------------------------QUICK SORT REC
int particionaVetor(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp);
void auxQuickSort(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp);
uint64_t quickSort(int vetor[], size_t tam);

//----------------------------------------------------HEAP SORT REC
void maxHeapfy(int *vetor, size_t i, size_t tam, uint64_t *heapComp);
void fazerMaxHeap(int *vetor, size_t tam, uint64_t *heapComp);
void auxHeapSort(int *vetor, size_t tam, uint64_t *heapComp);
uint64_t heapSort(int vetor[], size_t tam);

// As funções que terminam em SR são "Sem Recursão"
//----------------------------------------------------MERGE SORT SEM RECURSSÃO
size_t min(size_t x, size_t y);
void auxMergeSortRS(int *vetor, int *vetorAux, size_t tam, uint64_t *mergeComp);
uint64_t mergeSortSR(int vetor[], size_t tam);

//----------------------------------------------------QUICK SORT SEM RECURSSÃO
void auxQuickSortSR(int *vetor, size_t idxIni, size_t tam, uint64_t *quickComp);
uint64_t quickSortSR(int vetor[], size_t tam);

//----------------------------------------------------HEAP SORT SEM RECURSSÃO
void maxHeapfySR(int *vetor, size_t i, size_t tam, uint64_t *heapComp);
void auxHeapSortSR(int *vetor, size_t tam, uint64_t *heapComp);
uint64_t heapSortSR(int vetor[], size_t tam);

#endif  // ORDENACAO_H_