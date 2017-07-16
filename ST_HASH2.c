#include <stdlib.h>
#include "STitem.h"
#define used(A) (key(st[A]) != key(NULLitem))
extern int M, cnt1, cnt2;
static int N;
static STitem *st;
void STinit(int max){
    int i;
    N = 0;
    st = malloc(max*sizeof(STitem));
    for (i = 0; i < max; i++) st[i] = NULLitem;
}
int STcount(){ return N; }

int hash(Key v){ return v % M; }

int rehash(int i){ return (i+1) % M; }

void STinsert(STitem item){
    Key v = key(item);
    int i = hash(v);
    while (used(i)) { i = rehash(i); cnt1++; }
    st[i] = item; N++;
}

STitem STsearch(Key v){
    int i = hash(v);
    while (used(i))
    if eq(v, key(st[i])) return st[i];
    else { i = rehash(i); cnt2++; }
    return NULLitem;
}

void STshow(void){
    int i;
    for(i = 0; i < M; i++){ ITEMshow(st[i]); }
}
