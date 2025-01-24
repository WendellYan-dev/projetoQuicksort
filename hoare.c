#include <stdio.h>

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
        } else {
            return j;
        }
    }
}


void quicksortHoare(int lista[], int inicio, int fim) {
    if (inicio < fim) {
        int posicao = particionarHoare(lista, inicio, fim);
        quicksortHoare(lista, inicio, posicao);
        quicksortHoare(lista, p + 1, fim);
    }
}

void exibirArray(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}


int main() {
    int lista[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(lista) / sizeof(lista[0]); 

    printf("Array original: ");
    exibirArray(lista, n);

    quicksortHoare(lista, 0, n - 1);

    printf("Array ordenado: ");
    exibirArray(lista, n);

    return 0;
}