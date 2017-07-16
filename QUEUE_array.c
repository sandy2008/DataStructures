#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

static Item *s;
static int front, back;

void QUEUEinit(int maxN){
    s = malloc(maxN * sizeof(Item));
    front = 0;
    back = 0;
}

int QUEUEempty(void){
    return (front - back) == 0;
}

void QUEUEpush(Item x){
    s[back++] = x;
}

Item QUEUEpop(void){
    return s[front++];
}
