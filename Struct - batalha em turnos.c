#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int energia;
    int defesa;
    int forca;
} pers;

void executaRodada(pers x, pers y, int rodadas)
{
    int dano =0;
    for(int i =0; i<rodadas; i++)
    {

        if(y.energia!= 0 && x.energia != 0)
        {
            dano = x.forca-y.defesa;
            if(dano <= 0)
            {
                y.energia--;
            }
            else
            {
                y.energia-=dano;
                if(y.energia<=0)
                    y.energia=0;
            }
        }
        if(x.energia!= 0 && y.energia !=0)
        {

            dano=y.forca-x.defesa;
            if(dano<=0)
            {
                x.energia--;
            }
            else
            {
                x.energia-=dano;
                if(x.energia<=0)
                    x.energia=0;
            }
        }
    }

    if(x.energia == y.energia)
    {
        printf("%s %d",x.nome, x.energia);
        printf("\n%s %d",y.nome, y.energia);
        printf("\nempate");
    }
    else if(x.energia>y.energia)
    {

        printf("%s %d",x.nome, x.energia);
        printf("\n%s %d",y.nome, y.energia);
        printf("\n%s",x.nome);
    }
    else
    {

        printf("%s %d",x.nome, x.energia);
        printf("\n%s %d",y.nome, y.energia);
        printf("\n%s",y.nome);
    }

}

int main()
{
    int num;
    pers um, dois;
    scanf("%s %d %d %d",um.nome, &um.energia, &um.defesa,&um.forca);
    scanf("%s %d %d %d",dois.nome, &dois.energia, &dois.defesa,&dois.forca);
    scanf("%d", &num);
    executaRodada(um,dois,num);

    return 0;
}
