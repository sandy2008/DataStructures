#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;

void STACKinit(int maxN){
    s = malloc(maxN * sizeof(Item));
    N = 0;
}

int STACKempty(void){
    return N == 0;
}

void STACKpush(Item x){
    s[N++] = x;
}

Item STACKpop(void){
    return s[--N];
}
