#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode* link;

struct STACKnode{
    Item x;
    link next;
};

static link head;


void STACKinit(int maxN){
    head = NULL;
}

int STACKempty(void){
    return head == NULL;
}

Item STACKpop(void){
    Item x = head->item;
    link t = head->next;
    free(head);
    head = t;
    return x;
}

link insertFirst(Item n, link hd){
    link t = makeNew(n);
    t->next = hd;
    return t;
}

void STACKpush(Item x){
    head = insertFirst(x, head);
}


