#include <stdio.h>
#include <stdlib.h>

void minheap (int* x, int n, int d){
    int ls, rs, ts, ss;
    ls = 2 * d + 1;
    rs = 2 * d + 2;
    if (d <= ((n / 2) - 1)){
        if (rs < n){
            if (x [ls] < x [rs]){
                ts = ls;
            } else {
                ts = rs;
            }
        } else {
            ts = ls;
        }
        if (x [ts] < x [d]){
            ss = x [ts];
            x [ts] = x [d];
            x [d] = ss;
            minheap (x, n, ts);
        }
    }
}

void heapmin (int* x, int n){
    int d, ld;
    ld = (n / 2) - 1;
    for (d = ld; d >= 0; d--){
        minheap (x, n, d);
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
            heapmin (x, n);
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