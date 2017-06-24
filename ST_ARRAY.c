#include <stdlib.h>
#include "STitem.h"
static STitem *st;
static int N;
extern int cnt2;
extern int cnt1;
void STinit(int maxN){
st = malloc((maxN)*sizeof(STitem));
N = 0;
}
int STcount(void){ return N; }
void STshow(void){
int i;
for (i = 0; i < N; i++) ITEMshow(st[i]);
}
void STinsert(STitem x){
int j = N++;
Key v = key(x);
while (++cnt1 && j>0 && less(v, key(st[j-1]))){
st[j] = st[j-1]; j--;
}
st[j] = x;
}
STitem STsearch(Key v){
int j;
for (j = 0; j < N; j++){
if(++cnt2 && eq(v,key(st[j]))) return st[j];
if(++cnt2 && less(v, key(st[j]))) break;
}
return NULLitem;
}
