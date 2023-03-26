#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    float a, b, c;
} dados;

void dobraValores(float *a, float *b, float *c)
{
    *a = (*a) * 2;
    *b = (*b) * 2;
    *c = (*c) * 2;
}

int main()  
{
    int x;
    scanf("%d", &x);
    dados lidos[x];

    for (int i = 0; i < x; i++)
    {
        scanf("%f %f %f", &lidos[i].a, &lidos[i].b, &lidos[i].c);
        dobraValores(&lidos[i].a, &lidos[i].b, &lidos[i].c);
    }

    for (int i = 0; i < x; i++)
    {
        printf("A=%.1f B=%.1f C=%.1f", lidos[i].a, lidos[i].b, lidos[i].c, lidos[i].a + lidos[i].b + lidos[i].c);
    }
    return 0;
}
