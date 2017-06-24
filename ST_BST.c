#include <stdlib.h>
#include "STitem.h"
typedef struct STnode* link;
struct STnode { STitem item; link l, r; int N; };
static link head, pointNULL;
link makeNEW(STitem c,link left,link right,int num){
link x = malloc(sizeof *x);
x->item = c; x->l = left; x->r = right; x->N = num;
return x;
}
void STinit(void){
pointNULL = makeNEW(NULLitem,NULL,NULL,0);
head = pointNULL;
}
int STcount(void) { return head->N; }
STitem searchBST(link h, Key v){
Key t = key(h->item);
if(h == pointNULL) return NULLitem;
if(++cnt2 && eq(v,t)) return h->item;
if(++cnt2 && less(v,t))
return searchBST(h->l, v);
else return searchBST(h->r, v);
}
STitem STsearch(Key v){ return searchBST(head, v); }
STitem searchBST(link h, Key v){
Key t = key(h->item);
if(h == pointNULL) return NULLitem;
if(++cnt2 && eq(v,t)) return h->item;
if(++cnt2 && less(v,t))
return searchBST(h->l, v);
else return searchBST(h->r, v);
}
STitem STsearch(Key v){ return searchBST(head, v); }
link insertBST(link h, STitem x){
Key v = key(x), t = key(h->item);
if(h == pointNULL)
return makeNEW(x,pointNULL,pointNULL,1);
if(++cnt1 && less(v, t)) h->l = insertBST(h->l, x);
else h->r = insertBST(h->r, x);
(h->N)++; return h;
}
void STinsert(STitem x){ head = insertBST(head, x); }
void showBST(link h){
if (h == pointNULL) return;
showBST(h->l);
ITEMshow(h->item);
showBST(h->r);
}
void STshow(void){
showBST(head);
}
