#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    struct Item *prevItem;
    char mathsymbol;
};

struct Stack {
    struct Item *top;
    int quantity;
};

struct Stack *createStack (){
    struct Stack *s = (struct Stack*) malloc (sizeof(struct Stack));
    if (s != NULL){
        s -> top = NULL;
        s -> quantity = 0;
    }
    return s;
};

struct Item *createItem (char mathsym){
    struct Item *i = (struct Item*) malloc (sizeof(struct Item));
    if (i != NULL){
        i -> prevItem = NULL;
        i -> mathsymbol = mathsym;
    }
    return i;
};

void push (struct Stack *s, struct Item *i){
    i -> prevItem = s -> top;
    s -> top = i;
    s -> quantity++;
}

struct Item *pop (struct Stack *s){
    struct Item *delitem = s -> top;
    if (s -> top != NULL){
        s -> top = s -> top -> prevItem;
        s -> quantity--;
    }
    return delitem;
};

int main (){
    struct Stack *st1 = createStack ();
    struct Item *mathsym;
    int i, k, n, c, empty;
    char ms [100005];
    scanf ("%d\n", &n);
    for (i = 0; i < n; i++){
        empty = 0;
        c = 1;
        scanf ("%s", ms);
        for (k = 0; k < strlen (ms); k++){
            if (ms [k] == '(' || ms [k] == '[' || ms [k] == '{' || ms [k] == ')' || ms [k] == ']' || ms [k] == '}'){
                empty = 0;
                k = strlen (ms);
            } else {
                if (k == strlen (ms) - 1){
                    empty = 1;
                }
            }
        }
        printf ("%d", empty);
        if (empty = 1){
            printf ("S\n");
        } else {
            for (k = 0; k < strlen (ms); k++){
                if (ms [k] == '(' || ms [k] == '[' || ms [k] == '{'){
                    push (st1, createItem(ms[k]));
                } else if (ms [k] == ')' || ms [k] == ']' || ms [k] == '}'){
                    mathsym = pop (st1);
                    if (mathsym != NULL){
                        if (mathsym -> mathsymbol == '('){
                            if (ms [k] != ')'){
                                c = 0;
                                k = strlen (ms);
                            }
                        } else if (mathsym -> mathsymbol == '['){
                            if (ms [k] != ']'){
                                c = 0;
                                k = strlen (ms);
                            }
                        } else if (mathsym -> mathsymbol == '{'){
                            if (ms [k] != '}'){
                                c = 0;
                                k = strlen (ms);
                            }
                        }
                    } else {
                        c = 0;
                        k = strlen (ms);
                    }
                }
                if (k == strlen (ms) - 1 || k == strlen (ms)){
                    if (st1 -> top != NULL){
                        do {
                            mathsym = pop (st1);
                        } while (mathsym != NULL);
                        printf ("N\n");
                    } else {
                        if (c == 0){
                            printf ("N\n");
                        } else {
                            printf ("S\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}