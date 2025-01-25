#include <stdio.h>

int trocasTotais = 0;
int chamadasTotais = 0;

int mediana(int lista[],int inicio,int fim){
    int tamanho = (fim - inicio)+1;
    int l1 = lista[inicio+(tamanho/4)];
    int l2 = lista[inicio+(tamanho/2)];
    int l3 = lista[inicio+(3*tamanho/4)];

    //cálculo de uma mediana estável baseado no critério de entrada (inicio+(tamanho/4),inicio+(tamanho/2) e inicio+(3*tamanho/4))
    //caso base onde o elemento é o do meio
    if (l1 <=l2 && l2 <= l3) {
        return inicio+(tamanho/2); 
        //o de maior maior índice está no meio
    } else if (l1 <= l3 && l3 <= l2) {
        return inicio+(3*tamanho/4);
        //o de menor índice está no meio 
    } else if (l2 <= l1 && l1 <= l3) {
        return inicio+(tamanho/4); 
    } else if (l2 <= l3 && l3 <= l1) {
        return inicio+(3*tamanho/4);
    } else if (l3 <= l1 && l1 <= l2) {
        return inicio+(tamanho/4);
    } else {
        return inicio+(tamanho/2);
    }

}

//essa estruturs quicksort escolhe o primeiro elemento da lista como pivo
int particionarHoareMed(int lista[], int inicio, int fim) {
    //aqui encontramos o índice do pivo como proposto pelo slide
    int posicao = mediana(lista,inicio,fim);
    //aqui é criado um campo auxiliar que irá guardar o elemento na posição calculada(o pivo)
    int aux = lista[posicao];
    //o elemento nesta posição irá receber o que está no início da lista,para asim,trocarem de lugar
    lista[posicao] = lista[inicio];
    //aqui o elemento é copiado para o inicio da lista para assim tratarmos ele como um quicksort hoare(ordenação com pivo no início)
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


void hoareMediana(int lista[], int inicio, int fim) {
    chamadasTotais++;
    if (inicio < fim) {
        int posicao = particionarHoareMed(lista, inicio, fim);
        hoareMediana(lista, inicio, posicao);
        hoareMediana(lista, posicao + 1, fim);
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

    hoareMediana(lista, 0, n - 1);

    printf("Array ordenado: ");
    exibirArray(lista, n);

    printf("\nTrocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());

    return 0;
}