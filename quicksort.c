#include <stdio.h>
#include <stdlib.h>


void particiona(int *lista,int inicio,int fim) {
    //
    int pivo = (lista[inicio]+lista[fim]+lista[(inicio+fim)/2])/3;
    while(inicio<fim){
        while(inicio<fim && lista[inicio]<=pivo){
            inicio++;
        }
        while(inicio<fim && lista[fim]>pivo){
            fim--;
        }
        int aux = lista[inicio];
        lista[inicio] =lista[fim];
        lista[fim] = aux;
    }
    return inicio;
}

//deve ser fim-1
void quicksort(int *lista,int inicio,int fim){
    if(inicio<fim){
        int posicao = particiona(lista,inicio,fim);
        //sublista da esquerda
        quicksort(lista,inicio,posicao-1);
        //sublista da direita
        quicksort(lista,posicao+1,fim);
    }
}

int main() {

    int *lista = (int*)malloc(sizeof(int)*8);
    lista[0] = 3;
    lista[1] = 5;
    lista[2] = 8;
    lista[3] = 1;
    lista[4] = 2;
    lista[5] = 4;
    lista[6] = 7;
    lista[7] = 6;
    int tam = 8;
    quicksort(lista,0,tam-1);
    printf("Lista ordenada: ");
    for(int i = 0; i < tam; i++){
        printf("%d ",lista[i]);
    }

    return 0;
}