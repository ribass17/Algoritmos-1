#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float area,volume,cDiagonal;
}Paralelepipedo;

void atribuiValores(Paralelepipedo x,float *alt, float *larg, float *comp){
    x.area=(2*(*alt)*(*larg))+(2*(*alt)*(*comp))+(2*(*larg)*(*comp));
    x.volume=(*alt)*(*larg)*(*comp);
    x.cDiagonal=sqrt(pow(*alt,2)+pow(*larg,2)+pow(*comp,2));
}



int main() {
    float alt,larg,comp;
    scanf("%f %f %f",&alt,&larg,&comp);   
    atribuiValores(p,&alt,&larg,&comp);
    printf("area: %.1f\n",p.rea);
    printf("volume: %.1f\n",p.volume);
    printf("comprimento da diagonal: %.1f\n",p.cDiagonal);
    return 0;
}
