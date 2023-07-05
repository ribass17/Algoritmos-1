#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell
{
    char item[30];

    Cell *next;
};

struct ListaE
{
    Cell *head;
};

Cell *criar_celula(char *key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    strcpy(c->item, key);

    c->next = NULL;

    return c;
}

ListaE *criar_listaE()
{
    ListaE *l = (ListaE *)malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(char *key, ListaE *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void inserir_ultimo(char *key, ListaE *l)
{
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        aux = l->head;

        while (aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}

void imprimir(ListaE *l)
{
    Cell *aux;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%s", aux->item);
            printf("\n");
            aux = aux->next;
        }

    }
}

int liberar_LE(ListaE *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        while (l->head != NULL)
        {
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

int comparar_char(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    else if (c1 < c2)
        return -1;
    else
        return 0;
}

int comparar(char s1[], char s2[])
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}

void troca(char *x,char *y)
{
    char str[30];

    strcpy(str, x);
    strcpy(x, y);
    strcpy(y,str);
}

void selectSort(ListaE *l)
{
    if (l != NULL)
    {
        Cell *aux = l->head, *aux2;

        while (aux != NULL)
        {
            aux2 = aux->next;
            while (aux2 != NULL)
            {
                
                if (!(comparar(aux->item, aux2->item)))
                    troca(aux->item, aux2->item);
                aux2 = aux2->next;
            }
            aux = aux->next;
        }
    }
}

int main()
{
    int t;
    char aux[30];
    ListaE *x = criar_listaE();

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%s", aux);
        inserir_ultimo(aux, x);
    }
    selectSort(x);
    imprimir(x);
    liberar_LE(x);
    return 0;
}
