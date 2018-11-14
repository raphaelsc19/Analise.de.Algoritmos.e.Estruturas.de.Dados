#include <stdio.h>
#include <stdlib.h>

int ordenarBubble (int *v, int n, int troca){
    int i, j, k, reserva;
    if (troca == 0){
        for (i = 0; i < n; i++){
            if (i == n-1){
                printf ("%d", v [i]);
            } else {
                printf ("%d ", v [i]);
            }
        }
        printf ("\n");
    }
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-1-i; j++){
            if (v [j] > v[j+1]){
                reserva = v [j];
                v [j] = v [j+1];
                v [j+1] = reserva;
                troca++;
                for (k = 0; k < n; k++){
                    if (k == n-1){
                        printf ("%d", v [k]);
                    } else {
                        printf ("%d ", v [k]);
                    }
                }
                printf ("\n");
            }
        }
    }
    int m;
    for (m = 0; m < n; m++){
        if (m == n-1){
            printf ("%d", v [m]);
        } else {
            printf ("%d ", v [m]);
        }
    }
    printf ("\n");
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
    troca = ordenarBubble (v, n, troca);
    printf ("Trocas: %d\n", troca);
    return 0;
}