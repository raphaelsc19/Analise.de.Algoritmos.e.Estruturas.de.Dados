#include <stdio.h>
#include <stdlib.h>

void maxheap (int* x, int n, int d){
    int ls, rs, bs, ss; //left son, right son, bigger son, step son;
    ls = 2 * d + 1;
    rs = 2 * d + 2;
    if (d <= ((n / 2) - 1)){
        if (rs < n){
            if (x [ls] > x [rs]){
                bs = ls;
            } else {
                bs = rs;
            }
        } else {
            bs = ls;
        }
        if (x [bs] > x [d]){
            ss = x [bs];
            x [bs] = x [d];
            x [d] = ss;
            maxheap (x, n, bs);
        }
    }
}

void heapmax (int* x, int n){
    int d, ld; //dad, last dad;
    ld = (n / 2) - 1;
    for (d = ld; d >= 0; d--){
        maxheap (x, n, d);
    }
}

int main (){
    int i, on, n;
    on = 1;
    while (on != 0){
        scanf ("%d", &n);
        if (n == 0){
            on = 0;
        } else {
            int x [n];
            for (i = 0; i < n; i++){
                scanf ("%d", &x [i]);
            }
            heapmax (x, n);
            for (i = 0; i < n; i++){
                if (i == n - 1){
                    printf ("%d\n", x [i]);
                } else {
                    printf ("%d ", x [i]);
                }
            }
        }
    }
    return 0;
}