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

void heapsort (int* x, int n){
    int j, ord;
    if (n > 0){
        heapmax (x, n);
        for (j = 0; j < (n - 1); j++){
            printf ("%d ", x [j]);
        }
        printf ("%d\n", x [n - 1]);
        ord = x [0];
        x [0] = x [n - 1];
        x [n - 1] = ord;
        n--;
        heapsort (x, n);
    }
};

int main (){
    int i, n;
    scanf ("%d", &n);
    int x [n];
    for (i = 0; i < n; i++){
        scanf ("%d", &x [i]);
    }
    for (i = 0; i < (n - 1); i++){
        printf ("%d ", x [i]);
    }
    printf ("%d\n", x [n - 1]);
    heapsort (x, n);
        for (i = 0; i < (n - 1); i++){
        printf ("%d ", x [i]);
    }
    printf ("%d\n", x [n - 1]);
    return 0;
}