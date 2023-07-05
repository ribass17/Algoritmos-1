#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buscarReco(int chave, int *v, int i, int n) {
    if(v[0] == chave)
        return;
    if (i == n -1) {
        return;
    }
    if (v[i] == chave) {
        int aux = v[i];
        aux = v[i];
        for (i; i > 0; i--)
            v[i] = v[i - 1];
        v[i] = aux;

        return;
    }

    buscarReco(chave,v,i + 1, n);
}

int main() {

    int n,v,j=0, key;
    
    scanf("%d", &n);
    
    int x[n];
    
    for(int i =0; i < n; i++){
        scanf("%d", &x[i]);
    }
    
    scanf("%d", &v);
    
    for(int i=0; i<v; i++){
        scanf("%d",&key);
        buscarReco(key,x, j, n);
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", x[i]);
    }
    
    return 0;
}