#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, j, n, m, cont;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            m = -1;
            int x [n];
            for (i = 0; i < n; i++){
                scanf ("%d", &x[i]);
            }
            for (i = 0; i < n; i++){
                if (x [i] > m){
                    m = x [i];
                }
            }
            for (i = 0; i < (m + 1); i++){
                cont = 0;
                for (j = 0; j < n; j++){
                    if (x [j] == i){
                        cont++;
                    }
                }
                printf ("[%d] %d\n", i, cont);
            }
        }
    }
	return 0;
}