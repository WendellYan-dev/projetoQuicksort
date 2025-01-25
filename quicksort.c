#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trocasTotais = 0;
int chamadasTotais = 0;

//LOMUTO PADRÃO

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

//LOMUTO MED

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

//LOMUTO ALEATORIO

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

//HOARE PADRÃO

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
        trocasTotais++;
        } else {
            return j;
        }
    }
}


void quicksortHoare(int lista[], int inicio, int fim) {
    chamadasTotais++;
    if (inicio < fim) {
        int posicao = particionarHoare(lista, inicio, fim);
        quicksortHoare(lista, inicio, posicao);
        quicksortHoare(lista, posicao + 1, fim);
    }
}

//HOARE MEDIANA

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


//HOARE ALEATORIO

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

int totalProcedimentos() {
    return (trocasTotais + chamadasTotais);
}

void criarCopias(int *origem,int *destino,int tamanho) {
    memcpy(destino, origem, tamanho * sizeof(int));
}


int main() {
    FILE* arquivo = fopen("input.txt", "r");
    int numeroVetores, tamanhoVetor;
    if (arquivo == NULL) {
        printf("ERRO\n");
        return 0;
    }
    FILE* saida = fopen("output.txt", "w");
    if (saida == NULL) {
        printf("ERRO\n");
        return 0;
    }


    //leitura do número de vetores que estará na primeira linha do arquivo(especificado no slide)
    fscanf(arquivo, "%d", &numeroVetores);

    //Leitura dos contêineres com tamanho m usando um loop cadastrados no formato de entrada especificado no slide
    for (int i = 0; i < numeroVetores; i++) {
        fscanf(arquivo, "%d", &tamanhoVetor);
        int *vetorOriginal = malloc(tamanhoVetor * sizeof(int));
        int *copias[6];
        for (int k = 0; k < 6; k++) {
            copias[k] = malloc(tamanhoVetor * sizeof(int));
        }

        for (int j = 0; j < tamanhoVetor; j++) {
            fscanf(arquivo, "%d", &vetorOriginal[j]);
        }


        //LOMUTO PADRÃO
        criarCopias(vetorOriginal, copias[0], tamanhoVetor);
        quicksortLomuto(copias[0], 0, tamanhoVetor - 1);
        int somaLP = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;

        criarCopias(vetorOriginal, copias[1], tamanhoVetor);
        lomutoMed(copias[1], 0, tamanhoVetor - 1);
        int somaLM = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;

        criarCopias(vetorOriginal, copias[2], tamanhoVetor);
        lomutoAleatorio(copias[2], 0, tamanhoVetor - 1);
        int somaLA = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;

        criarCopias(vetorOriginal, copias[3], tamanhoVetor);
        quicksortHoare(copias[3], 0, tamanhoVetor - 1);
        int somaHP = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;

        criarCopias(vetorOriginal, copias[4], tamanhoVetor);
        hoareMediana(copias[4], 0, tamanhoVetor - 1);
        int somaHM = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;

        criarCopias(vetorOriginal, copias[5], tamanhoVetor);
        hoareAleatorio(copias[5], 0, tamanhoVetor - 1);
        int somaHA = totalProcedimentos();
        trocasTotais = 0;
        chamadasTotais = 0;
        
        fprintf(saida, "%d:N(%d),P(%d),LM(%d),LA(%d),HP(%d),HM(%d),HA(%d)\n",i,tamanhoVetor, somaLP, somaLM, somaLA, somaHP, somaHM, somaHA);
        free(vetorOriginal);
        for (int k = 0; k < 6; k++) {
            free(copias[k]);
        }
    }

    fclose(arquivo);
    fclose(saida);

    return 0;
}