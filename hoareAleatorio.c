#include <stdio.h>
#include <stdlib.h>

int trocasTotais = 0;
int chamadasTotais = 0;

//essa estruturs quicksort escolhe o primeiro elemento da lista como pivo
int particaoHoareAleatorio(int lista[], int inicio, int fim) {
    //tamanho relativo real do vetor
    int tamanho = (fim - inicio)+ 1;
    //aqui encontramos o índice do pivo como proposto pelo slide
    int posicao = inicio+(abs(lista[inicio]))%tamanho;
    //aqui é criado um campo auxiliar que irá guardar o elemento na posição calculada(o pivo)
    int aux = lista[posicao];
    //o elemento nesta posição irá receber o que está no início da lista,para assim,trocarem de lugar
    lista[posicao] = lista[inicio];
    //aqui o elemento é copiado para o iniício da lista para assim tratarmos ele como um quicksort hoare(ordenação com pivo no inicio)
    lista[inicio] = aux;
    trocasTotais++;

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


void hoareAleatorio(int lista[], int inicio, int fim) {
    chamadasTotais++;
    if (inicio < fim) {
        int posicao = particaoHoareAleatorio(lista, inicio, fim);
        hoareAleatorio(lista, inicio, posicao);
        hoareAleatorio(lista, posicao + 1, fim);
    }
}

void exibirArray(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int totalProcedimentos() {
    return trocasTotais + chamadasTotais;
}


int main() {
    int lista[] = {834 ,27 ,39 ,19 ,3 ,-1 ,-33}; 
    int n = sizeof(lista) / sizeof(lista[0]); 

    printf("Array original: ");
    exibirArray(lista, n);

    hoareAleatorio(lista, 0, n - 1);

    printf("Array ordenado: ");
    exibirArray(lista, n);

    printf("\nTrocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());

    return 0;
}