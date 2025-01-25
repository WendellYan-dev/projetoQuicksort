#include <stdio.h>
#include <stdlib.h>

int trocasTotais = 0;
int chamadasTotais = 0;

int particao(int lista[],int inicio,int fim){
    //tamanho relativo real do vetor
    int tamanho = (fim - inicio)+ 1;
    //aqui encontramos o índice do pivo como proposto pelo slide
    int posicao = inicio+(abs(lista[inicio]))%tamanho;
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

void lomutoAleatorio(int lista[],int inicio,int fim){
    chamadasTotais++;
    if(inicio<fim){
        int posicao = particao(lista,inicio,fim);
        lomutoAleatorio(lista,inicio,posicao-1);
        lomutoAleatorio(lista,posicao+1,fim);
    }
}

int totalProcedimentos() {
    return trocasTotais + chamadasTotais;
}

int main() {

    int lista[] = {847 ,38 ,-183 ,-13 ,94 ,-2 ,-42 ,54 ,28 ,100};
    int tamanho = sizeof(lista)/sizeof(lista[0]);

    lomutoAleatorio(lista, 0 ,tamanho-1);
    for(int i = 0;i<tamanho;i++){
    printf(" %d ",lista[i]);
    }
    printf("Trocas: %d\nChamadas: %d\nTotal: %d\n", trocasTotais, chamadasTotais, totalProcedimentos());

    return 0;
}