#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, n, cd, tm, ml;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            int x [n];
            ml = 0;
            for (i = 0; i < n; i++){
                scanf ("%d", &x [i]);
                tm = x [i];
                cd = 0;
                if (tm == 0){
                    cd = 1;
                }
                while (tm != 0){
                    cd++;
                    tm = tm/10;
                }
                if (cd > ml){
                    ml = cd;
                }
            }
            printf ("%d\n", ml);
        }
    }
	return 0;
}