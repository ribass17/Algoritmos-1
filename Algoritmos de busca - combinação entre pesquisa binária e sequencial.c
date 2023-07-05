#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


static int buscaBinSeq(int key,int *vet,int n, int min){
    int esquerda =  0, direita = n - 1, posicao = -1,meio;
   
    while(direita - esquerda + 1 > min){
        meio = (direita + esquerda) / 2;
        if (key == vet[meio])
            return meio;
        else if (key > vet[meio])
            esquerda = meio + 1;
        else
            direita =  meio - 1;        
    }
    for(int i = esquerda; i < (direita+1); i++){
        if(vet[i] == key)
            posicao = i;
        printf("%d ", vet[i]);
    }
    printf("\n");
    return posicao;
}

int main(void){
    int x,size, min;

    scanf ("%d", &x);
    scanf ("%d", &size);

    int *vet = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        scanf ("%d", &vet[i]);

    scanf ("%d", &min);

    printf("%d\n", buscaBinSeq(x, vet, size, min));

    return 0;
}


