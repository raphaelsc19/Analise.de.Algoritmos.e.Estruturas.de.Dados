#include <stdio.h>
#include <stdlib.h>

int catalan(int n){
    if (n==0){
        return 1;
    } else {
        return ((((4*n)-2)*catalan(n-1))/(n+1));
    }
}

int main(){
	int x, i;
	scanf("%d", &x);
	while(x!=-1){
		i = catalan(x);
		printf("%d\n", i);
		scanf("%d", &x);
	}
	return 0;
}