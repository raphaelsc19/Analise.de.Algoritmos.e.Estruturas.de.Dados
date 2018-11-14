#include <stdio.h>
#include <stdlib.h>

void cs (int* x, int n){
    int i, j, m;
    for (i = 0; i < n; i++){
        if (i == 0){
            m = x [0];
        } else {
            if (x [i] > m){
                m = x [i];
            }
        }
    }
    int vc [m + 1];
    int vo [n];
    for (i = 0; i < (m + 1); i++){
        vc [i] = 0;
        for (j = 0; j < n; j++){
            if (x [j] == i){
                vc [i]++;
            }
        }
    }
    for (i = 1; i < (m + 1); i++){
        vc [i] = vc [i] + vc [i - 1];
    }
    for (i = 0; i < n; i++){
        vo [vc [x [i]] - 1] = x [i];
        vc [x [i]]--;
    }
    for (i = 0; i < n; i++){
        x [i] = vo [i];
    }
}

int main (){
    int i, n;
    n = 1;
    while (n != 0){
        scanf ("%d", &n);
        if (n != 0){
            int x [n];
            for (i = 0; i < n; i++){
                scanf ("%d", &x [i]);
            }
            cs (x, n);
            for (i = 0; i < n - 1; i++){
                printf ("%d ", x [i]);
            }
            printf ("%d\n", x [n - 1]);
        }
    }
	return 0;
}