#include <stdio.h>

#include "Item.h"
#include "STACK.h"
#define MAX 1000

int main(void)
{
    int x;

    STACKinit(MAX);
    STACKpush(10);
    STACKpush(30);
    STACKpush(40);

    x = STACKpop();
    printf("%d",x);

    STACKpush(50);
    x = STACKpop();
    printf("%d",x);
}
