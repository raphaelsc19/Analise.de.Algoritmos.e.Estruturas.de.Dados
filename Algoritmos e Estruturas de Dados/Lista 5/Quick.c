#include <stdio.h>
#include <stdlib.h>

int particiona (int* vetor, int st, int en, int n){
    int i, j, org, part;
    part = st - 1;
    for (i = st; i < en; i++){
        if (vetor [i] <= vetor [en]){
            part++;
            org = vetor [i];
            vetor [i] = vetor [part];
            vetor [part] = org;
        }
        for (j = 0; j < n; j++){
            if (j == n - 1){
                printf ("%d\n", vetor [j]);
            } else {
                printf ("%d ", vetor [j]);
            }
        }
    }
    org = vetor [en];
    vetor [en] = vetor [part + 1];
    vetor [part + 1] = org;
    return (part + 1);
}

void quick (int* vetor, int st, int en, int n){
    int i, quebra;
    if (en > st){
        quebra = particiona (vetor, st, en, n);
        for (i = 0; i < n; i++){
            if (i == n - 1){
                printf ("%d\n", vetor [i]);
            } else {
                printf ("%d ", vetor [i]);
            }
        }
        quick (vetor, st, quebra - 1, n);
        quick (vetor, quebra + 1, en, n);
    }
}

int main (){
    int i, n, x, st, en;
    st = 0;
    scanf ("%d", &n);
    en = n - 1;
    int vetor [n];
    for (i = 0; i < n; i++){
        scanf ("%d", &x);
        vetor [i] = x;
    }
    for (i = 0; i < n; i++){
        if (i == n - 1){
            printf ("%d\n", vetor [i]);
        } else {
            printf ("%d ", vetor [i]);
        }
    }
    quick (vetor, st, en, n);
    for (i = 0; i < n; i++){
        if (i == n - 1){
            printf ("%d\n", vetor [i]);
        } else {
            printf ("%d ", vetor [i]);
        }
    }
	return 0;
}