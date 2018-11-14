#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converte(char letra){
    int chave;
    if(letra == 'A'){
        chave = 1;
    }
    else if(letra =='B'){
        chave = 2;
    }
    else if(letra =='C'){
        chave = 3;
    }
    else if(letra =='D'){
        chave = 4;
    }
    else if(letra =='E'){
        chave = 5;
    }
    else if(letra =='F'){
        chave = 6;
    }
    else if(letra =='G'){
        chave = 7;
    }
    else if(letra =='H'){
        chave = 8;
    }
    else if(letra =='I'){
        chave = 9;
    }
    else if(letra =='J'){
        chave = 10;
    }
    else if(letra =='K'){
        chave = 11;
    }
    else if(letra =='L'){
        chave = 12;
    }
    else if(letra =='M'){
        chave = 13;
    }
    else if(letra =='N'){
        chave = 14;
    }
    else if(letra =='O'){
        chave = 15;
    }
    else if(letra =='P'){
        chave = 16;
    }
    else if(letra =='Q'){
        chave = 17;
    }
    else if(letra =='R'){
        chave = 18;
    }
    else if(letra =='S'){
        chave = 19;
    }
    else if(letra =='T'){
        chave = 20;
    }
    else if(letra =='U'){
        chave = 21;
    }
    else if(letra =='V'){
        chave = 22;
    }
    else if(letra =='W'){
        chave = 23;
    }
    else if(letra =='X'){
        chave = 24;
    }
    else if(letra =='Y'){
        chave = 25;
    }
    else{
        chave = 26;
    }
    return chave;
}

struct tNo{
	struct tNo *esq, *dir;
	struct tNo *pai;
	int chave;
	char letra;
};

struct tArvore{
	struct tNo *raiz;
};

struct tNo* criaNo(char letra){
	struct tNo *novo = (struct tNo*)malloc(sizeof(struct tNo));
	int chave = converte(letra);
	if(novo != NULL){
		novo->esq = novo->dir = novo->pai = NULL;
		novo->letra = letra;
		novo->chave = chave;
	}
	return novo;
}

struct tArvore* criaArvore(){
	struct tArvore *novo = (struct tArvore*)malloc(sizeof(struct tArvore));
	if(novo != NULL){
		novo->raiz = NULL;
	}
	return novo;
}

struct tNo* procuraPai(struct tArvore *arvore, struct tNo *novo){
	struct tNo *pai = NULL, *filho = arvore->raiz;
	while(filho != NULL){
		pai = filho;
		if(novo->chave >= filho->chave)
			filho = filho->dir;
		else
			filho = filho->esq;	
	}
	return pai;
}

void insere(struct tArvore *arvore, struct tNo *novo){
	struct tNo *pai;
	if(arvore->raiz == NULL){
		arvore->raiz = novo;
	}
	else{
		pai = procuraPai(arvore, novo);
		novo->pai = pai;
		if(novo->chave >= pai->chave)
			pai->dir = novo;
		else
			pai->esq = novo;
	}
}

struct tNo* procuraElemento(struct tArvore *arvore, int chave){
	struct tNo *no = arvore->raiz;	
	int achei = 0;
	while(no != NULL && !achei){
		if(chave == no->chave)
			achei = 1;		
		else{
			if(chave >= no->chave)
				no = no->dir;
			else
				no = no->esq;
		}
	}
	return no;
}

struct tNo* sucessor(struct tNo *no){
    no = no->dir;
    while(no != NULL && no->esq != NULL){
        no = no->esq;
    }
    return no;
}

struct tNo* antecessor(struct tNo *no){
    no = no->esq;
    while(no != NULL && no->dir != NULL){
        no = no->dir;
    }
    return no;
}

struct tNo* exclue(struct tArvore *arvore, int chave){
	struct tNo *no = procuraElemento(arvore, chave), *pai, *suc;
	if(no == NULL)
		return NULL;
	else{
	    pai = no->pai;
	    if(pai == NULL){
	        if(no->esq == NULL && no->dir == NULL){
			    arvore->raiz = NULL;
		    }
		    else if(no->esq == NULL && no->dir != NULL){
		        arvore->raiz = no->dir;
		        no->dir->pai = NULL;
		    }
		    else if(no->esq != NULL && no->dir == NULL){
		        arvore->raiz = no->esq;
		        no->esq->pai = NULL;
		    }
		    else{
		        suc = sucessor(no);
                if(no->dir->esq != NULL){
                    if(suc->dir != NULL){
	                    suc->pai->esq = suc->dir;
	                    suc->dir->pai = suc->pai;
                    }
                    else{
                    	suc->pai->esq = NULL;
                    }
                    suc->dir = no->dir;
                    no->dir->pai = suc;
                }
                arvore->raiz = suc;
                suc->pai = NULL;
                no->esq->pai = suc;
                suc->esq = no->esq;
		    }
		    return no;
	    }
	    else{
		    if(no->esq == NULL && no->dir == NULL){
			    if(no->chave >= pai->chave)
				    pai->dir = NULL;
			    else
				    pai->esq = NULL;
		    }
		    else if(no->esq == NULL && no->dir != NULL){
		        if(no->chave >= pai->chave){
		            pai->dir = no->dir;
		            no->dir->pai = pai;
		        }
		        else{
		            pai->esq = no->dir;
		            no->dir->pai = pai;
		        }
		    }
		    else if(no->esq != NULL && no->dir == NULL){
		        if(no->chave >= pai->chave){
		            pai->dir = no->esq;
		            no->esq->pai = pai;
		        }
		        else{
		            pai->esq = no->esq;
		            no->esq->pai = pai;
		        }
		    }
		    else{
                suc = sucessor(no);
                if(no->chave >= pai->chave)
                    pai->dir = suc;
                else
	                pai->esq = suc;
                if(no->dir->esq != NULL){
                    if(suc->dir != NULL){
	                    suc->pai->esq = suc->dir;
	                    suc->dir->pai = suc->pai;
                    }
                    else{
                    	suc->pai->esq = NULL;
                    }
                    suc->dir = no->dir;
                    no->dir->pai = suc;
                }
                suc->pai = pai;
                no->esq->pai = suc;
                suc->esq = no->esq;
		    }
		    return no;
	    }
	}
}

void inOrder(struct tNo *no){
	if(no != NULL){
		inOrder(no->esq);
		printf("%c ", no->letra);
		inOrder(no->dir);
	}
}

void preOrder(struct tNo *no){
	if(no != NULL){
		printf("%c ", no->letra);
		preOrder(no->esq);
		preOrder(no->dir);
	}
}

void posOrder(struct tNo *no){
	if(no != NULL){
		posOrder(no->esq);
		posOrder(no->dir);
		printf("%c ", no->letra);
	}
}

int main()
{
    struct tArvore *arvore = criaArvore();
    struct tNo *rem;
    char op[15], letra;
    int chave;
    
    while(scanf("\n%s", op)!=EOF){
        if(strcmp(op, "pre-order") == 0)
        {
            preOrder(arvore->raiz);
            printf("\n");
        }
        else if(strcmp(op, "in-order") == 0)
        {
            inOrder(arvore->raiz);
            printf("\n");
        }
        else if(strcmp(op, "post-order") == 0)
        {
            posOrder(arvore->raiz);
            printf("\n");
        }
        else if(strcmp(op, "insert") == 0)
        {
            scanf(" %c", &letra);
            insere(arvore, criaNo(letra));
        }
        else
        {
            scanf(" %c", &letra);
            chave = converte(letra);
            rem = exclue(arvore, chave);
            if(rem != NULL)
            {
                free(rem);
            }
        }
    }
    return 0;
}