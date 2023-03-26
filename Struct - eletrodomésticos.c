    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>

    typedef struct
    {
        char nome[30];
        int pot;
        float temp;
        float cRel;
    } eletro;

    int consumoIndividal(eletro x, int dias)
    {
        return (x.pot*x.temp*dias);
    }

    void medeConsumo(eletro x[], int ele, int dias)
    {
        int total;
        for(int i=0; i <ele; i++)
        {
            total+=consumoIndividal(x[i], dias);
        }
        for(int i=0; i<ele; i++)
        {
            x[i].cRel=(float)total/consumoIndividal(x[i],dias);
        }
        printf("%d\n", total);
        for(int i=0; i<ele; i++)
        {
            printf("%s %.2f\n", x[i].nome, x[i].cRel);
        }
    }

    int main(void)
    {
        int x, dias;
        scanf("%d", &x);
        eletro casa[x];
        for(int i = 0; i<x; i++)
        {
            scanf("%s %d %f",casa[i].nome,&casa[i].pot,&casa[i].temp);
        }
        scanf("%d", &dias);
        medeConsumo(casa,x,dias);

    }
