#include <stdio.h>
#include <stdlib.h>

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


int particaoMed(int lista[],int inicio,int fim){
    //aqui encontramos o índice do pivo como proposto pelo slide
    int posicao = mediana(lista,inicio,fim);
    //aqui é criado um campo auxiliar que irá guardar o elemento na posição calculada(o pivo)
    int aux = lista[posicao];
    //o elemento nesta posição irá receber o que está no final da lista,para asim,trocarem de lugar
    lista[posicao] = lista[fim];
    //aqui o elemento é copiado para o final da lista para assim tratarmos ele como um quicksort lomuto(ordenação com pivo no final)
    lista[fim] = aux;
    trocasTotais++;

    //esse índice será usado para avançar nossa lista somente quando encontrar valores menores ou iguais ao nosso pivo
    //ele inicia "fora da lista" por não ter elementos ainda verificados
    int j = inicio-1;

    //aqui então é feita a cópia e transferência do nosso pivo para o final da lista
    int pivo = lista[fim];
    for(int i =inicio;i<fim;i++){
        if(lista[i]<=pivo){
            j++;
            int aux = lista[j];
            lista[j] = lista[i];
            lista[i]= aux;
            trocasTotais++;
        }
    }
    aux = lista[j+1];
    lista[j+1] = lista[fim];
    lista[fim] = aux;
    trocasTotais++;
    return j+1;
}

void lomutoMed(int lista[],int inicio,int fim){
    chamadasTotais++;
    if(inicio<fim){
        int posicao = particaoMed(lista,inicio,fim);
        lomutoMed(lista,inicio,posicao-1);
        lomutoMed(lista,posicao+1,fim);
    }
}

int totalProcedimentos() {
    return trocasTotais + chamadasTotais;
}

int main() {

    int lista[] = {847 ,38 ,-183 ,-13 ,94 ,-2 ,-42 ,54 ,28 ,100};
    int tamanho = sizeof(lista)/sizeof(lista[0]);

    lomutoMed(lista, 0 ,tamanho-1);
    for(int i = 0;i<tamanho;i++){
    printf(" %d ",lista[i]);
    }
    printf("Trocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());

    return 0;
}