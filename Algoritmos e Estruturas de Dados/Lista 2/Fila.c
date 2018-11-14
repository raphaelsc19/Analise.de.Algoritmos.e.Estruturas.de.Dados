#include <stdio.h>
#include <stdlib.h>

struct tFila {
		int *id;
		int inicio, fim, tamanho;
};

struct tAluno {
		char ra, nome;
	};

void iniciafila (struct tFila *atendimento, int n){
	atendimento -> id = (struct tAluno*) malloc (n*sizeof(aluno))
	atendimento -> tamanho = n;
	atendimento -> inicio = -1;
	atendimento -> fim = -1;
}

void iniciaaluno (struct tAluno *aluno){
	aluno -> ra;
	aluno -> nome;
}

void addaluno (struct tAluno *aluno, char ra, char nome){
	aluno.ra = ra;
	aluno.nome = nome;
}

void delaluno (){
	
}

void atende (){
    //tira
    atendimento.inicio++;
    printf ("[%c] %c", ra, nome); //terminar ra e nome
}

void entrafila (){
	if (atendimento.inicio == -1 && atendimento.fim == -1){
		atendimento.fim++;
		//entra no índice fim
		atendimento.inicio++;
	} else if (atendimento.inicio != -1 && atendimento.inicio == atendimento.fim){
		//não faz nada
	} else {
		atendimento.fim++;
		//entra no índice fim
	}
}

void imprimefila (struct tFila *atendimento){
	int i;
	for (i = atendimento.inicio; i <= atendimento.fim ; i++){
		printf ("[%c] %c", atendimento.aluno.ra[i], atendimento.aluno.nome[i]);
	}
}

void inversafila (struct tFila *atendimento){
	int i;
	for (i = atendimento.fim; i >= atendimento.inicio ; i--){
		printf ("[%c] %c", atendimento.aluno.ra[i], atendimento.aluno.nome[i]);
	}
}

void quantidadefila (struct tFila *atendimento){
	int print = ((atendimento.fim - atendimento.inicio) + 1);
	printf ("Quantidade: %d", print);
}

int main(){
	int n;
	char op, nome[100], ra[15];
	struct tFila atendimento;
	struct tAluno aluno;
	scanf ("%d", &n);
	iniciafila (atendimento, n);
	iniciaaluno (aluno);
	scanf ("%c", &op);
	if (op == "I"){
		scanf (" %c %c\n", ra, nome);
		addaluno(aluno, ra, nome);
		entrafila();
	} else if (op == "A"){
		atende ();
		delaluno();
		//deletar aluno
	} else if (op == "Q"){
		quantidadefila (atendimento);
	} else if (op == "M"){
		imprimefila ();
	} else if (op == "R"){
		inversafila ();
	}
	free (atendimento.aluno);
	return 0;
}
