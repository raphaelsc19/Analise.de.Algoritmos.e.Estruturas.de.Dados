#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, j, n, m, acum;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            int x [n];
            m = -1;
            for (i = 0; i < n; i++){
                scanf ("%d", &x[i]);
            }
            for (i = 0; i < n; i++){
                if (x [i] > m){
                    m = x [i];
                }
            }
            for (i = 0; i < (m + 1); i++){
                acum = 0;
                for (j = 0; j < n; j++){
                    if (x [j] <= i){
                        acum++;
                    }
                }
                printf ("[%d] %d\n", i, acum);
            }
        }
    }
	return 0;
}