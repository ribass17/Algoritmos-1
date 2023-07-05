
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 10

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
};


Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}


int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}


int enfileirar(Fila *f, int chave){
    if (f == NULL)
        f = criar_fila();

    if (!fila_cheia(f)){
        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}


int desenfileirar(Fila *f){
    int item = INT_MIN;

    if (!fila_vazia(f)){
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}


void imprimir_fila(Fila *f){
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

int tamanho_fila(Fila *f){
    if (f != NULL)
        return f->tam;
    else
        return 0;
}

int valorIicio(Fila *x){
    return x->item[x->ini];
}
int valorFim(Fila *x){
    return x->item[x->fim];
}
void enfileirarOrdenada(Fila *x, int key){
    
    if(x == NULL)
        x = criar_fila();
    if(fila_vazia(x) || key < valorFim(x)){
        enfileirar(x, key);
    }else if(!fila_cheia(x)){
        Fila *aux = criar_fila();
        while(!fila_vazia(x)){
            if(key > valorIicio(x)){
                enfileirar(aux, key);
                key = INT_MIN;
            }   
            else 
                enfileirar(aux, desenfileirar(x));
        }
        while(!fila_vazia(aux))
          enfileirar(x,desenfileirar(aux));
    }
    
}
int main() {
    int i = 0;
    Fila *a = criar_fila();
    while(i != -1){
        scanf("%d", &i);
        if(i != -1)
            enfileirarOrdenada(a, i);
    }
    imprimir_fila(a);
    liberar_fila(a);
    return 0;
}
