#include <stdio.h>
#include <stdlib.h>


int mediana(int lista[],int inicio,int fim){
    int tamanho = (fim - inicio)+1;
    int l1 = lista[inicio+(tamanho/2)];
    int l2 = lista[inicio+(tamanho/4)];
    int l3 = lista[inicio+(3*tamanho/4)];

    //cálculo de uma mediana estável baseado no critério de entrada (inicio+(tamanho/4),inicio+(tamanho/2) e inicio+(3*tamanho/4))
    //caso base onde o elemento é o do meio
    if((l1>=l2 && l1<=l3) || (l1<=l2 && l1>=l3)){
        return inicio+(tamanho/2);
    } else if((l2>l1 && l2<l3) || (l2<l1 && l2<l3)){
        return inicio+(tamanho/4);
    } else {
        return inicio+(3*tamanho/4);
    }

}


int main(){

    int vetor[] = {2,1,2};
    int med = mediana(vetor,0,2);
    printf("%d", med);

}