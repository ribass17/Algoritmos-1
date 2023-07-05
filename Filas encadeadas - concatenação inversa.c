#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#define TAM_MAX 100

typedef struct Cell Cell;


typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};


struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};


Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}


int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}


int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(Pilha *p){
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d", item);
    }
    
    printf("\n");
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}


void concaIvert(FilaE *um, FilaE *dois, FilaE *tres)
{
    Pilha *aux = criar_pilha();
    if(tres == NULL)
        tres = criar_filaE();
    if (um != NULL)
    {
        while (!filaE_vazia(um))
            empilhar(aux, desenfileirar(um));
        while (!pilha_vazia(aux))
            enfileirar(desempilhar(aux), tres);
    }
    if (dois != NULL)
    {
        while (!filaE_vazia(dois))
            empilhar(aux, desenfileirar(dois));
        while (!pilha_vazia(aux))
            enfileirar(desempilhar(aux), tres);
    }
    liberar_pilha(aux);
}

int main()
{
    int x;
    FilaE *um, *dois, *tres;
    um = criar_filaE();
    dois = criar_filaE();
    tres = criar_filaE();
        
    while (x != -1)
    {
        scanf("%d", &x);
        if(x != -1)
            enfileirar(x,um);
    }
    x=0;
    while (x != -1)
    {
        scanf("%d", &x);
        if(x != -1)
            enfileirar(x,dois);
    }
    
    concaIvert(um,dois,tres);
    imprimir_fila(tres);
    
    
    liberar_filaE(um);
    liberar_filaE(dois);
    liberar_filaE(tres);
    return 0;
}
