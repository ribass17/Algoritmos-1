#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int restoDivisao(int dividendo, int divisor) {
    if (dividendo < divisor)
        return dividendo;
    else
        return restoDivisao(dividendo - divisor, divisor);
}
int main() {
    int n,a,b;
    scanf("%d", &n);
    for(int i =0;i < n; i++){
        scanf("%d %d", &a,&b);
        printf("%d\n", restoDivisao(a,b));
    }
}
