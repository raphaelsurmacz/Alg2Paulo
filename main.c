#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR];
    int numComp;

    int tamVetor = 100000;
    int* vetor = (int*)malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

//----------------------------------------------------MERGE SORT REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------MergeSortR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
	numComp = mergeSort(vetor, tamVetor);
    printf("NumComp: %d\n", numComp);
    printf("Impressão do vetor ordenado:\n\n");
	imprimeVetor(vetor, tamVetor);

//----------------------------------------------------QUICK SORT REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------QuickSortR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
    numComp = quickSort(vetor, tamVetor);
    printf("NumComp: %i\n", numComp);
    printf("Impressão do vetor ordenado:\n\n");
    imprimeVetor(vetor, tamVetor);

//----------------------------------------------------HEAP SORT REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------HeapSortR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
    numComp = heapSort(vetor, tamVetor);
    printf("NumComp: %d\n", numComp);
    printf("Impressão do vetor ordenado:\n\n");
    imprimeVetor(vetor, tamVetor);

//----------------------------------------------------MERGE SORT SEM REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------MergeSortSR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
    numComp = mergeSortSR(vetor, tamVetor);
    printf("NumComp: %d\n", numComp);
    printf("Impressão do vetor ordenado:\n");
    imprimeVetor(vetor, tamVetor);

//----------------------------------------------------QUICK SORT SEM REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------QuickSortSR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
    numComp = quickSortSR(vetor, tamVetor);
    printf("NumComp: %d\n", numComp);
    printf("Impressão do vetor ordenado:\n");
    imprimeVetor(vetor, tamVetor);

//----------------------------------------------------HEAP SORT SEM REC
    preencheVetor(vetor, tamVetor);
    printf("\n----------------------HeapSortSR-------------------\nImpressão do vetor a ser ordenado:\n");
    imprimeVetor(vetor, tamVetor);
    numComp = heapSortSR(vetor, tamVetor);
    printf("NumComp: %d\n", numComp);
    printf("Impressão do vetor ordenado:\n");
    imprimeVetor(vetor, tamVetor);

    free(vetor);

    return 0;
}
