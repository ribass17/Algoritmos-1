#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectsort2(int v[], int n){
    int i, j, p, aux;
    
    for (i = 0; i < n - 1;  i++){
        p = i;
    
        for (j = i + 1; j < n; j++)
            if (v[j] > v[p])
                p = j;
        
        if (p != i){
            aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
    }
}

int** lermat(int **mat, int m,int n){
    for(int i=0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d ", &mat[i][j]);
        }
    }
    return mat;
}

void ordenaMat(int **x, int m,int n){
    if(x != NULL){
        for(int i=0; i<m; i++){
            selectsort2(x[i], n);
        }
    }
}


int main() {
    int m, n, **mat;
    scanf("%d %d", &m,&n);
    mat = malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++)
        mat[i] = malloc(n * sizeof(int));
    
    mat = lermat(mat,m,n);
    ordenaMat(mat, m,n);
    
    for(int i=0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%d ", mat[i][j]) ;
        }
        printf("\n");
    }
    
    

    free(mat);
}
