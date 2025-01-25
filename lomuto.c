#include <stdio.h>
#include <stdlib.h>

int trocasTotais = 0;
int chamadasTotais = 0;

//no quicksort lomuto o pivo será o último índice da lista
int particionaLomuto(int lista[],int inicio,int fim) {

    //como o lomuto é um tipo de quicksort que sua ordenação é baseada na posição do pivo no final da lista,inicia-se ele no índice final dela
    int pivo = lista[fim];
    int i = inicio;
    for(int j = inicio;j < fim;j++){
        if(lista[j]<=pivo){
            //aqui estamos comparando e avançando o índice i na nossa lista com base nos elementos que sejam menores ou iguais ao pivo
            //fazendo com o que,todo elemento menor ou igual a ele,fique sempre á sua esquerda 
            int aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            i++;
            trocasTotais++;
        }
    }
    int aux = lista[i];
    lista[i] = lista[fim];
    lista[fim] = aux;
    trocasTotais++;
    return i;
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

int totalProcedimentos() {
    return trocasTotais + chamadasTotais;
}

int main() {

    int lista[] = {847 ,38 ,-183 ,-13 ,94 ,-2 ,-42 ,54 ,28 ,100};
    int tamanho = sizeof(lista)/sizeof(lista[0]);

    quicksortLomuto(lista, 0 ,tamanho-1);
    for(int i = 0;i<tamanho;i++){
    printf(" %d ",lista[i]);
    }
    printf("Trocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());

    return 0;
}