#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, n, k;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            scanf ("%d", &k);
            for (i = 1; i < k; i++){
                n = n/10;
            }
            n = n % 10;
            printf ("%d\n", n);
            n = 1;
        }
    }
	return 0;
}