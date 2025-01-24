#include <stdio.h>
#include <stdlib.h>

//no quicksort lomuto o pivo será o último índice da lista
int particionaLomuto(int lista[],int inicio,int fim) {

    int pivo = lista[fim];
    int i = inicio;
    for(int j = inicio;j < fim;j++){
        if(lista[j]<=pivo){
            int aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            i++;
        }
    }
    int aux = lista[i];
    lista[i] = lista[fim];
    lista[fim] = aux;
    return i;
}


void quicksortLomuto(int lista[],int inicio,int fim){
    if(inicio<fim){
        int posicao = particionaLomuto(lista,inicio,fim);
        //sublista da esquerda
        quicksortLomuto(lista,inicio,posicao-1);
        //sublista da direita
        quicksortLomuto(lista,posicao+1,fim);
    }
}

int main() {

    int lista[] = {9, 7 , 4, 23 , 10, -5};
    int tamanho = sizeof(lista)/sizeof(lista[0]);

    quicksortLomuto(lista, 0 ,tamanho-1);
    for(int i = 0;i<tamanho;i++){
    printf(" %d ",lista[i]);
    }


    return 0;
}