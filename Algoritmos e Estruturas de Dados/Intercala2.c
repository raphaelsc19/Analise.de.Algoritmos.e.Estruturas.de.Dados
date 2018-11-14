#include <stdio.h>
#include <stdlib.h>

void intercalar (int n, int q1, int* vi, int* vf){
	int i, x, y;
	x = 0;
	y = q1;
	for (i = 0; i < n; i++){
		if (x < q1 && y < n){
			if (vi [x] <= vi [y]){
				vf [i] = vi [x];
				x++;
			} else {
				vf [i] = vi [y];
				y++;
			}
		} else if (x < q1){
			vf [i] = vi [x];
			x++;
		} else if (y < n){
			vf [i] = vi [y];
			y++;
		}
	}
}

int main(){
	int i, q1, q2, n;
	scanf ("%d %d", &q1, &q2);
	n = q1 + q2;
	int vi [n], vf [n];
	for (i = 0; i < q1; i++){
		scanf ("%d", &vi [i]);
	}
	for (i; i < n; i++){
		scanf ("%d", &vi [i]);
	}
	intercalar (n, q1, vi, vf);
	for (i = 0; i < n; i++){
		printf ("%d\n", vf [i]);
	}
	return 0;
}