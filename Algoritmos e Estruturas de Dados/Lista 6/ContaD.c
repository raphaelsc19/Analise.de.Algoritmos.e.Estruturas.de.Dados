#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, n, cd;
    n = 1;
    while (scanf ("%d", &n) != EOF){
        cd = 0;
        if (n == 0){
            cd = 1;
        } else {
            while (n != 0){
                cd++;
                n = n/10;
            }
        }
        printf ("%d\n", cd);
    }
	return 0;
}