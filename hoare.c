#include <stdio.h>

int particionarHoare(int arr[], int inicio, int fim) {
    int pivo = arr[inicio]; //Escolhe o primeiro elemento como pivô
    int i = inicio - 1;     
    int j = fim + 1;        

    while (1) {
        // Avança o índice esquerdo até encontrar um elemento maior ou igual ao pivô
        do {
            i++;
        } while (arr[i] < pivo);
        // Retrocede o índice direito até encontrar um elemento menor ou igual ao pivô
        do {
            j--;
        } while (arr[j] > pivo);
        // Se os índices se cruzaram, retorna o ponto de partição
        if (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        } else {
            return j;
        }
    }
}

// Função QuickSort recursiva
void quicksortHoare(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice de partição
        int p = particionarHoare(arr, inicio, fim);

        // Ordena a sublista à esquerda do pivô
        quicksortHoare(arr, inicio, p);

        // Ordena a sublista à direita do pivô
        quicksortHoare(arr, p + 1, fim);
    }
}

// Função para exibir o array
void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Array de exemplo
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array original: ");
    exibirArray(arr, n);

    // Chama o QuickSort para ordenar o array
    quicksortHoare(arr, 0, n - 1);

    printf("Array ordenado: ");
    exibirArray(arr, n);

    return 0;
}