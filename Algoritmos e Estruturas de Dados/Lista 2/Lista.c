#include <stdio.h>
#include <stdlib.h>

struct tLista {
		int *item;
		int tamanho;
		int quantidade;
};

void inicialista (struct tLista *lista, int q){
	lista -> item = (int*) malloc (q*sizeof(int));
	lista -> tamanho = q;
	lista -> quantidade = 0;
}

int busca (struct tLista *lista, int it){
	int i = 0;
	while (i < lista -> tamanho || lista -> item [i] != it){
		i++;
	}
	if (i == lista -> tamanho){
		return 0;
	} else {
		return i;
	}
}

void inclui (struct tLista *lista, int it){
	if (lista -> quantidade = 0){
		lista -> item [0] = it;
		lista -> quantidade++;
	} else {
		int j = busca (&lista, it);
		if (j == 0){
			int i;
			for (i = 0; i < lista -> quantidade; i++){
				if (lista -> item [i] > it){
					deslocadireita (&lista, i);
					lista -> item [i] = it;
					i = lista -> quantidade;
				}
			}
			lista -> quantidade++;
		}
	}
}

void deslocadireita (struct tLista *lista, int i){
	int k;
	for (k = lista -> quantidade; k > i; k--){
		lista -> item [k] = lista -> item [k-1];
	}
}

void deslocaesquerda (struct tLista *lista, int i){
	int k;
	for (k = i; k < lista -> quantidade; k++){
		lista -> item [k] = lista -> item [k+1];
	}
}

void exclui (struct tLista *lista, int it){
	int j = busca (&lista, it);
	if (j != 0){
		lista -> item [j] = NULL;
		deslocaesquerda(&lista, j);
		lista -> quantidade--;
	}
}

int main (){
	int i, q, it;
	char op;
	scanf ("%d\n", &q);
	struct tLista lista;
	inicialista (&lista, q);
	for (i = 0; i < q; i++){
		scanf ("%c %d\n", &op, &it);
		if (op == 'I'){
			inclui (&lista, it);
		} else if (op == 'E'){
			exclui (&lista, it);
		}
	}
	for (i = 0; i < q; i++){
		if (lista -> item [i] != NULL){
			printf ("%d\n", lista -> item [i]);
		}
	}
	return 0;
}
