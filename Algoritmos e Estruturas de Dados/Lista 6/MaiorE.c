#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, n, m, pm;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            int x [n];
            for (i = 0; i < n; i++){
                scanf ("%d", &x[i]);
            }
            for (i = 0; i < n; i++){
                if (i == 0){
                    m = x [0];
                    pm = 0;
                } else {
                    if (x [i] > m){
                        m = x [i];
                        pm = i;
                    }
                }
            }
            printf ("%d %d\n", pm, m);
        }
    }
	return 0;
}