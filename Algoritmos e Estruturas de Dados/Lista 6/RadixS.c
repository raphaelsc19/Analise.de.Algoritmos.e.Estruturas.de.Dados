#include <stdio.h>
#include <stdlib.h>

struct sFila (){
    int* inicio, fim;
    int quant;
};

struct criaFila (){
    struct sFila *fx = (int*) malloc (sizeof (struct sFila));
    if (fx != NULL){
        fx -> inicio = NULL;
        fx -> fim = NULL;
        fx -> quant = 0;
    }
    return fx;
};

struct Item (){
    int dado;
    int* prox;
};

struct criaItem (int x){
    struct Item *it = (int*) malloc (sizeof (struct Item));
    if (it != NULL){
        it -> dado = x;
        it -> prox = NULL;
    }
    return it;
};

void insereFila (struct sFila *fx, int h){
    criaItem (h);
    if (fx -> quant == 0){
        fx -> inicio = it;
        fx -> fim = it;
        fx -> quant++;
    } else {
        fx -> fim -> prox = it;
        fx -> quant++;
    }
}

void esvFila (struct sFila *fx, int* x){
    int i;
    for (i = 0; i < fx -> quant; i++){
        x [i] = fx -> inicio -> dado;
    }
}

int ml (int* x, int n){
    int i, m, cd, tm;
    m = 0;
    for (i = 0; i < n; i++){
        tm = x [i];
        cd = 0;
        if (tm == 0){
            cd = 1;
        }
        while (tm != 0){
            cd++;
            tm = tm/10;
        }
        if (cd > m){
            m = cd;
        }
    }
    return m;
}

void rs (int* x, int n){
    int i, j, k, h, m;
    int* fila;
    for (i = 0; i < 10; i++){
        fila [i] = criaFila ();
    }
    m = ml (x, n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            h = x [j];
            for (k = 0; k < i; k++){
                h = h/10;
            }
            h = h % 10;
            //if h == 0, str x [j] na fila 0. if h == 1, str x [j] na fila 1. etc
        }
    }
    for (i = 0; i < 10; i++){
        esvFila (fila [i]);
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
            rs (x, n);
        }
    }
	return 0;
}