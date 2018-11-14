#include <stdio.h>
#include <stdlib.h>

void intercalar (int* v, int e, int m, int d){
	int i, x, y;
	int g [d + 1];
	for (i = 0; i < (d + 1); i++){
	    g [i] = v [i];
	}
	x = e;
	y = m;
	for (i = e; i < (d + 1); i++){
		if (x < m && y < (d + 1)){
			if (g [x] <= g [y]){
				v [i] = g [x];
				x++;
			} else {
				v [i] = g [y];
				y++;
			}
		} else if (x < m){
			v [i] = g [x];
			x++;
		} else if (y < (d + 1)){
			v [i] = g [y];
			y++;
		}
	}
}

void merge (int* vetor, int n, int e, int d){
    int i, meio;
    if (e < d){
        meio = (d + e)/2;
        merge (vetor, n, e, meio);
        merge (vetor, n, meio + 1, d);
        for (i = 0; i < n; i++){
            if (i >= n - 1){
                printf ("%d\n", vetor [i]);
            } else {
                printf ("%d ", vetor [i]);
            }
        }
        intercalar (vetor, e, meio + 1, d);
    }
}

int main(){
    int i, n, x, e, d;
    scanf ("%d", &n);
    int vetor [n];
    for (i = 0; i < n; i++){
        scanf ("%d", &x);
        vetor [i] = x;
    }
    for (i = 0; i < n; i++){
        if (i >= n - 1){
            printf ("%d\n", vetor [i]);
        } else {
            printf ("%d ", vetor [i]);
        }
    }
    e = 0;
    d = n - 1;
    merge (vetor, n, e, d);
    for (i = 0; i < n; i++){
        if (i >= n - 1){
            printf ("%d\n", vetor [i]);
        } else {
            printf ("%d ", vetor [i]);
        }
    }
	return 0;
}