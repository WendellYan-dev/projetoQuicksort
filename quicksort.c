#include <stdio.h>
#include <stdlib.h>

int trocasTotais = 0;
int chamadasTotais = 0;



//essa estruturs quicksort escolhe o primeiro elemento da lista como pivo
int particionarHoare(int lista[], int inicio, int fim) {
    int pivo = lista[inicio]; 
    int i = inicio - 1;     
    int j = fim + 1;        

    while (1) {
        do {
            i++;
        } while (lista[i] < pivo);
        do {
            j--;
        } while (lista[j] > pivo);
        if (i < j) {
        int temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
        trocasTotais++;
        } else {
            return j;
        }
    }
}


void quicksortHoare(int lista[], int inicio, int fim) {

    chamadasTotais++;
    if (inicio < fim) {
        int posicao = particionarHoare(lista, inicio, fim);
        quicksortHoare(lista, inicio, posicao);
        quicksortHoare(lista, posicao + 1, fim);
    }
}

void quicksortLomuto(int lista[],int inicio,int fim){
    chamadasTotais++;
    if(inicio<fim){
        int posicao = particionaLomuto(lista,inicio,fim);
        //sublista da esquerda
        quicksortLomuto(lista,inicio,posicao-1);
        //sublista da direita
        quicksortLomuto(lista,posicao+1,fim);
    }
}

void exibirVetor(int vetor[], int tamanhoVetor) {
    for(int i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int totalProcedimentos() {
    return trocasTotais + chamadasTotais;
}

void copiaVetorOriginal(int vetor[], int vetorOriginal[], int tamanhoVetor) {
    for(int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = vetorOriginal[i];
    }
}

int main() {

    int totalVetores,tamanhoVetor;
    int *vetor, *vetorOriginal;

    scanf("%d", &totalVetores);
    for (int i = 0; i < totalVetores; i++) {
        scanf("%d", &tamanhoVetor);
        vetorOriginal = (int*)malloc(tamanhoVetor*sizeof(int));
        if (vetorOriginal == NULL) {
            printf("ERRO\n");
            return 0;
        }
        vetor = (int*)malloc(tamanhoVetor*sizeof(int));
        if (vetor == NULL) {
            printf("ERRO\n");
            return 0;
        }
        for(int j = 0; j < tamanhoVetor; j++) {
            scanf("%d", &vetor[j]);
        }
        copiaVetorOriginal(vetorOriginal, vetor, tamanhoVetor);

        //contadores reiniciam em cada vetor em 0,evitando todos os vetores terem seus procedimentos todos somados
        trocasTotais = 0;
        chamadasTotais = 0;
        quicksortHoare(vetor, 0, tamanhoVetor-1);
        exibirVetor(vetor, tamanhoVetor);
        printf("Trocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());
        // printf("Trocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, total);
        // quicksortLomuto(vetorOriginal, 0, tamanhoVetor-1);
        // exibirVetor(vetorOriginal, tamanhoVetor);
        free(vetor);
    }   

    return 0;
}