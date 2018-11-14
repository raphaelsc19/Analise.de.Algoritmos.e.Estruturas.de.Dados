#include <stdio.h>
#include <stdlib.h>

struct LDDE {
		struct ItemLista *primeiro, *ultimo;
		int quantidade;
};

struct ItemLista {
    int dado;
    struct ItemLista *proximo, *anterior;
};

struct LDDE *criaLDDE (){
    struct LDDE *lista = (struct LDDE*) malloc (sizeof(struct LDDE));
    if (lista != NULL){
        lista -> primeiro = NULL;
        lista -> ultimo = NULL;
        lista -> quantidade = 0;
    }
    return lista;
};

struct ItemLista *criaItem (int it){
    struct ItemLista *item = (struct ItemLista*) malloc (sizeof(struct ItemLista));
    if (item != NULL){
        item -> dado = it;
        item -> anterior = NULL;
        item -> proximo = NULL;
    }
    return item;
};

void inserir (struct LDDE *lista, struct ItemLista *item){
    struct ItemLista *atual = lista -> primeiro, *anterior = NULL;
    int i = 0;
    while (!i && atual != NULL){
        if (atual -> dado > item -> dado){
            i = 1;
        } else {
            anterior = atual;
            atual = atual -> proximo;
        }
    }
    item -> proximo = atual;
    item -> anterior = anterior;
    if (anterior != NULL){
        anterior -> proximo = item;
    } else {
        lista -> primeiro = item;
    }
    if (atual != NULL){
        atual -> anterior = item;
    } else {
        lista -> ultimo = item;
    }
    lista -> quantidade++;
}

struct ItemLista *excluir (struct LDDE *lista, int it){
    struct ItemLista *atual = lista -> primeiro, *anterior = NULL;
    int i = 0;
    while (!i && atual != NULL){
        if (atual -> dado == it){
            i = 1;
        } else {
            anterior = atual;
            atual = atual -> proximo;
        }
    }
    if (i == 1){
        if (anterior == NULL){
            lista -> primeiro = atual -> proximo;
            if (lista -> quantidade == 1){
                lista -> ultimo = NULL;
            } else {
                atual -> proximo -> anterior = NULL;
            }
        } else if (atual -> proximo == NULL){
            lista -> ultimo = atual -> anterior;
            atual -> anterior -> proximo = NULL;
        } else {
            atual -> proximo -> anterior = atual -> anterior;
            atual -> anterior -> proximo = atual -> proximo;
        }
        lista -> quantidade--;
    }
    return atual;
}

void imprime (struct ItemLista *item){
    if (item != NULL){
        printf ("%d ", item -> dado);
        imprime (item -> proximo);
    }
}

void imprimerev (struct ItemLista *item){
    if (item != NULL){
        printf ("%d ", item -> dado);
        imprimerev (item -> anterior);
    }
}

int main (){
    struct LDDE *listadde = criaLDDE ();
    struct ItemLista *item;
    int dado;
    char op;
    while (scanf ("\n%c", &op) != EOF){
        if (op == 'I'){
            scanf ("%d", &dado);
            inserir (listadde, criaItem(dado));
        } else if (op == 'E'){
            scanf ("%d", &dado);
            item = excluir (listadde, dado);
            if (item != NULL){
                free (item);
            }
        } else if (op == 'M'){
            imprime (listadde -> primeiro);
            printf ("\n");
        } else if (op == 'R'){
            imprimerev (listadde -> ultimo);
            printf ("\n");
        }
    }
    return 0;
}
