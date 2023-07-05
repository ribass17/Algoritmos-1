#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

struct Cell {
    char item;
    Cell *next;
};


struct PilhaE {
    Cell *topo;
};


Cell* criar_celula(int key) {
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE() {
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p) {
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(int key, PilhaE *p) {
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


int desempilhar(PilhaE *p) {
    Cell *aux;
    int item = -1;

    if (!pilhaE_vazia(p)) {
        aux = p->topo;

        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}


void imprimir_pilha(PilhaE *p) {
    Cell *aux;

    if (!pilhaE_vazia(p)) {
        aux = p->topo;

        while (aux != NULL) {
            printf("%d", aux->item);
            aux = aux->next;
        }
    }
}


int liberar_pilha(PilhaE *p) {
    if (p != NULL) {
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

void imprimir_hexadecimal(PilhaE *p) {
    Cell *aux;

    if (!pilhaE_vazia(p)) {
        aux = p->topo;

        while (aux != NULL) {
            if(aux->item >=10 && aux->item <=16){
                printf("%c", aux->item+87);
            }else   
                printf("%d", aux->item);
            aux = aux->next;
        }
    }
}

PilhaE *toBase(int nmr, int base) {
    PilhaE *aux = criar_pilhaE();
    if(base >= 2 && base <= 16) {
        while(nmr != 0) {
            empilhar(nmr%base, aux);
            nmr /= base;
        }
    }
    return aux;
}



int main(void) {
    int num, base;
    PilhaE *x;
    scanf("%d %d", &num,& base);
    x = toBase(num,base);
    if(base == 16)
        imprimir_hexadecimal(x);
    else
        imprimir_pilha(x);
    liberar_pilha(x);
}
