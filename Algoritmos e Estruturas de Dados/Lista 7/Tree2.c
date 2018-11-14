#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tArvore * criaArvore();
struct tNo * criaNo(char);
struct tNo * sucessor(struct tArvore *, struct tNo *);
struct tNo * antecessor(struct tArvore *, struct tNo *);
struct tNo * remover(struct tArvore *, char);
void inserir(struct tArvore *, struct tNo *);
void preOrdem(struct tNo*);
void inOrdem(struct tNo*);
void posOrdem(struct tNo*);

struct tNo
{
    char chave;
    struct tNo *esquerda, *direita, *pai;
};

struct tArvore
{
    struct tNo *raiz;
};

struct tArvore * criaArvore()
{
    struct tArvore *t = (struct tArvore*) malloc(sizeof(struct tArvore));
    if(t!=NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct tNo * criaNo(char chave)
{
    struct tNo *it = (struct tNo*) malloc(sizeof(struct tNo));
    if(it!=NULL)
    {
        it->chave = chave;
        it->direita = it->esquerda = it->pai = NULL;
    }
    return it;
}

void inserir(struct tArvore *t, struct tNo *novo)
{
    struct tNo *pai = NULL, *filho = t->raiz;
    if(t->raiz == NULL)
    {
        t->raiz = novo;
    }
    else
    {
        while(filho!=NULL)
        {
            pai=filho;
            if(filho->chave > novo->chave)
                filho=filho->esquerda;
            else
                filho=filho->direita;
        }
        if(pai->chave > novo->chave)
            pai->esquerda = novo;
        else
            pai->direita = novo;
        novo->pai = pai;
    }
}

void preOrdem(struct tNo *raiz)
{
    if(raiz!=NULL)
    {
        printf("%c ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void inOrdem(struct tNo *raiz)
{
    if(raiz!=NULL)
    {
        inOrdem(raiz->esquerda);
        printf("%c ", raiz->chave);
        inOrdem(raiz->direita);
    }
}

void posOrdem(struct tNo *raiz)
{
    if(raiz!=NULL)
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%c ", raiz->chave);
    }
}

struct tNo * sucessor(struct tArvore *t, struct tNo *r)
{
    struct tNo *pai;
    while(r != NULL)
    {
        pai = r;
        r = r->esquerda;
    }
    pai = remover(t, pai->chave);
    return pai;
}

struct tNo * antecessor(struct tArvore *t, struct tNo *r)
{
    struct tNo *pai;
    while(r != NULL)
    {
        pai = r;
        r = r->direita;
    }
    pai = remover(t, pai->chave);
    return pai;
}

struct tNo * remover(struct tArvore *t, char k)
{
    struct tNo *filho=t->raiz, *pai=NULL, *suc;
    
    while(filho!=NULL && filho->chave!=k)
    {
        pai = filho;
        if(filho->chave > k)
        {
            filho = filho->esquerda;
        }
        else
        {
            filho = filho->direita;
        }
    }
    
    if(filho!=NULL)
    {
        if(filho->esquerda == NULL && filho->direita == NULL)
        {
            if(filho != t->raiz)
            {
                if(pai->esquerda == filho)
                {
                    pai->esquerda = NULL;
                }
                else
                {
                    pai->direita = NULL;
                }
            }
            else
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL)
        {
            suc = sucessor(t, filho->direita);
            if(pai!=NULL)
            {
                if(pai->esquerda == filho)
                {
                    pai->esquerda = suc;
                }
                else
                {
                    pai->direita = suc;
                }
            }
            else
            {
                t->raiz = suc;
            }
            suc->pai = pai;
            suc->direita = filho->direita;
            suc->esquerda = filho->esquerda;
            filho->direita->pai = suc;
            filho->esquerda->pai = suc;
        }
        else
        {
            if(pai != NULL)
            {
                if(pai->esquerda == filho)
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->esquerda = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->esquerda = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
                else
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->direita = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->direita = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
            }
            else
            {
                if(filho->esquerda != NULL)
                {
                    t->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                }
                else
                {
                    t->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }
        }
    }
    return filho;
}

int main (){
    struct tArvore *arvore = criaArvore ();
    struct tNo *rem;
    char op [15];
    char chave;
    while (scanf ("\n%s", op) != EOF){
        if (strcmp (op, "pre-order") == 0){
            preOrdem (arvore -> raiz);
            printf ("\n");
        } else if (strcmp (op, "in-order") == 0){
            inOrdem (arvore -> raiz);
            printf ("\n");
        } else if (strcmp (op, "post-order") == 0){
            posOrdem (arvore -> raiz);
            printf ("\n");
        } else if (strcmp (op, "insert") == 0){
            scanf ("\n%c", &chave);
            inserir (arvore, criaNo(chave));
        } else {
            if (strcmp (op, "delete") == 0){
                scanf ("\n%c", &chave);
                rem = remover (arvore, chave);
                if (rem != NULL){
                    free (rem);
                }
            }
        }
    }
    return 0;
}