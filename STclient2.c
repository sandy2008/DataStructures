#include <stdio.h>
#include <stdlib.h>
#include "STitem.h"
#include "ST.h"
int M = 20;
int cnt1, cnt2;
void main(void){
int i;
STinit(M);
STitem items[10];
int tmp[10] = {4, 24, 5, 35, 25, 13, 26, 87, 38, 44};
for(i = 0; i < 10; i++){
items[i] = NULLitem;
key(items[i]) = tmp[i];
}
for(i = 0; i < 10; i++) STinsert(items[i]);
printf("Resulting Symbol Table\n"); STshow(); printf("\n");
printf("Search 44\n");
ITEMshow(STsearch(44));
printf("Rehashing %d-times (insertion)\n", cnt1);
printf("Rehashing %d-times (searching)\n", cnt2);
return;
}
