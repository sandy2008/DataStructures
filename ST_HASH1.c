#include <stdlib.h>
#include "STitem.h"

extern int cnt2;

typedef struct STnode* link;
struct STnode { STitem item; link next; };

static link insertNew(STitem item, link next){
    link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
}

static link *heads, pointNULL;
static int N, M;

void STinit(int max){
    int i;
    N = 0; M = max/5;
    heads = malloc(M*sizeof(link));
    pointNULL = insertNew(NULLitem, NULL);
    for (i = 0; i < M; i++) heads[i] = pointNULL;
}

int hash(Key v) { return v % M; }

int STcount(void){ return N; }

STitem STsearch(Key v){
link t = heads[hash(v)];
while(t != pointNULL){
    if (++cnt2 && eq(key(t->item),v))
        return t->item;
    t = t->next;
}
    return NULLitem;
}

void STinsert(STitem item){
    int i = hash(key(item));
    heads[i] = insertNew(item, heads[i]);
    N++;
}

void STshow(void){
    int i; link tmp;
    for(i = 0; i < M; i++){
    tmp = heads[i];
    while(tmp != pointNULL){
        ITEMshow(tmp->item);
        tmp = tmp->next;
        }
    }
}


