#include <stdio.h>
#include <stdlib.h>

int ordenarInsertion (int *vetor, int n, int troca){
    int chave, i, j;
    for (i = 1; i < n; i++){
        chave = vetor [i];
        j = i-1;
        while (j >= 0 && vetor [j] >= chave){
            vetor [j+1] = vetor [j]
            vetor [j] = chave
            j + j - 1
        }
    }
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
    troca = ordenarInsertion (v, n, troca);
    printf ("Trocas: %d\n", troca);
    if (troca == 0){
        printf ("MELHOR CASO\n");
    } else if (troca == (((n*n)-n)/2)){
        printf ("PIOR CASO\n");
    } else {
        printf ("CASO ALEATORIO\n");
    }
    return 0;
}
