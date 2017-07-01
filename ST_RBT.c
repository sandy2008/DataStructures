#include <stdlib.h>
#include "STitem.h"
typedef struct STnode* link;
struct STnode {
	STitem item;
	link l, r;
	int N;
	int red;
};
static link head, pointNULL;
extern int cnt1, cnt2;

link makeNEW(STitem c,link left,link right,int num,int col;){
link x = malloc(sizeof *x);
x->item = c; x->l = left; x->r = right; x->N = num; x->red = col;
return x;
}

link rotR(link h){
link x = h->l;
h->l = x->r;
x->r = h;
return x; 
}

link rotL(link h){
link x = h->r;
h->r = x->l;
x->l = h;
return x; 
}

void fixN(link h){
if (h == pointNULL) { return; }
fixN(h->l);
fixN(h->r);
h->N = (h->l->N)+(h->r->N)+1;
return;
}

void STinit(void){
pointNULL = makeNEW(NULLitem,NULL,NULL,0,0);
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

link RBinsert(link h, STitem item, int sw){
Key v = key(item);
if (h == pointNULL) return makeNEW(item,pointNULL,pointNULL,1,1);
if ((hl->red) && (hr->red)){
h->red = 1; hl->red = 0; hr->red = 0; }
if (++cnt1 && less(v, key(h->item))){
hl = RBinsert(hl, item, 0);
if (h->red && hl->red && sw) h = rotR(h);
if (hl->red && hll->red){
h = rotR(h); h->red = 0; hr->red = 1; }
}
else{
hr = RBinsert(hr, item, 1);
if (h->red && hr->red && !sw) h = rotL(h);
if (hr->red && hrr->red){
h = rotL(h); h->red = 0; hl->red = 1; }
}
fixN(h); return h;
}

void STinsert(STitem item){
head = RBinsert(head, item, 0);
head->red = 0;
}

void showBST(link h){
if (h == pointNULL) return;
showBST(h->l);
ITEMshow(h->item);
showBST(h->r);
}

void STshow(void){
showBST(head);
}
