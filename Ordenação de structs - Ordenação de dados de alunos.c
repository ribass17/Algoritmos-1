#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[30];
    char curso[30];
    float coef;
}Aluno;

int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 > c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}




void selectsort(Aluno *v, int n){
    int i, j, p;
    Aluno aux;
    
    for (i = n - 1; i >= 1;  i--){
        p = i;
    
        for (j = 0; j < i; j++)
            if ((comparar(v[j].nome,v[p].nome)) == -1)
                p = j;
            else if((comparar(v[j].nome,v[p].nome)) == 0)
                if(v[j].matricula > v[p].matricula)
                     p=j;
                   
        
        aux = v[i];
        v[i] = v[p];
        v[p] = aux;
    }
}


int main() {
    int x;
    scanf("%d", &x);
    Aluno list[x];
    for(int i = 0; i < x; i++){
        scanf("%d", &list[i].matricula);
        fflush(stdin); 
        scanf("%s", list[i].nome);
        fflush(stdin);
        scanf("%s", list[i].curso);
        scanf("%f", &list[i].coef);
    }
    selectsort(list,x);
    for(int i = 0; i < x; i++){
        printf("%s ", list[i].nome);
        printf("%d ", list[i].matricula);
        printf("%s ", list[i].curso);
        printf("%.2f\n", list[i].coef);
    }
    
    
    return 0;
}

