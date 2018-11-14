#include <stdio.h>
#include <stdlib.h>

int ordenarSelection (int *v, int n, int troca){
    int i, j, k, m, aux, iMin;
    for (i = 0; i < n-1; i++){
        for (j = i+1, iMin = i; j < n; j++){
            if (v [j] < v [iMin]){
                iMin = j;
                troca++;
            }
        }
        aux = v [i];
        v [i] = v [iMin];
        v [iMin] = aux;
        for (m = 0; m < n; m++){
            if (m == n-1){
                printf ("%d\n", v [m]);
            } else {
                printf ("%d ", v [m]);
            }
        }
    }
    for (k = 0; k < n; k++){
        if (k == n-1){
            printf ("%d\n", v [k]);
        } else {
            printf ("%d ", v [k]);
        }
    }
    return troca;
}

int main (){
    int n, i, valor, troca;
    troca = 0;
    scanf ("%d\n", &n);
    int v [n];
    for (i = 0; i < n; i++){
        scanf ("%d", &valor);
        v [i] = valor;
    }
    for (i = 0; i < n; i++){
        if (i == n-1){
            printf ("%d\n", v [i]);
        } else {
            printf ("%d ", v [i]);
        }
    }
    troca = ordenarSelection (v, n, troca);
    printf ("%d\n", troca);
    return 0;
}
