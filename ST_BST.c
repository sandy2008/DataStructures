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
