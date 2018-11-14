#include <stdio.h>
#include <stdlib.h>

void intercalar (int n, int q1, int q2, int* vr, int* vq1, int* vq2){
	int i, x, y;
	x = 0;
	y = 0;
	for (i = 0; i < n; i++){
		if (x < q1 && y < q2){
			if (vq1 [x] <= vq2 [y]){
				vr [i] = vq1 [x];
				x++;
			} else {
				vr [i] = vq2 [y];
				y++;
			}
		} else if (x < q1){
			vr [i] = vq1 [x];
			x++;
		} else if (y < q2){
			vr [i] = vq2 [y];
			y++;
		}
	}
}

int main(){
	int i, q1, q2, n;
	scanf ("%d %d", &q1, &q2);
	n = q1 + q2;
	int vq1 [q1], vq2 [q2], vr [n];
	for (i = 0; i < q1; i++){
		scanf ("%d", &vq1 [i]);
	}
	for (i = 0; i < q2; i++){
		scanf ("%d", &vq2 [i]);
	}
	intercalar (n, q1, q2, vr, vq1, vq2);
	for (i = 0; i < n; i++){
		printf ("%d\n", vr [i]);
	}
	return 0;
}