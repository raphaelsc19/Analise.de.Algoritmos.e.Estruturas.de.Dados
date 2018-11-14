#include <stdio.h>
#include <stdlib.h>

void particiona (int q, int p, int* vetor){
    int i, org, part;
    part = -1;
    org = vetor [q - 1];
    vetor [q - 1] = vetor [p];
    vetor [p] = org;
    for (i = 0; i < (q - 1); i++){
        if (vetor [i] < vetor [q - 1]){
            part++;
            org = vetor [i];
            vetor [i] = vetor [part];
            vetor [part] = org;
        }
    }
    org = vetor [q - 1];
    vetor [q - 1] = vetor [part + 1];
    vetor [part + 1] = org;
}

int main(){
    int q, p, i, x;
    scanf ("%d", &q);
    scanf ("%d", &p);
    int vetor [q];
    for (i = 0; i < q; i++){
        scanf ("%d", &x);
        vetor [i] = x;
    }
    particiona (q, p, vetor);
    for (i = 0; i < q; i++){
        printf ("%d\n", vetor [i]);
    }
	return 0;
}