#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STitem.h"
#include "ST.h"
STitem newItem = {300,"New Item"};
int cnt1 = 0, cnt2 = 0;
void main(int argc, char *argv[]){
int i, sKey, M = atoi(argv[1]), sw = atoi(argv[2]);
int maxN = M + 1;
Key v; STitem item;
STinit(maxN);
srand(2);
for (i = 0; i < M; i++){
switch(sw){
case 0: v = ITEMrand(); break;
case 1: v = i+1; break;
default: if(ITEMscan(&v) == EOF) break;
}
key(item) = v;
strcpy(info(item), "Hello");
STinsert(item);
}
printf("Original Symbol Table\n"); STshow();
printf("Length = %d, Keys = %d\n\n", M, STcount());
STinsert(newItem);
printf("After insertion\n"); STshow();
printf("Input sKey: "); scanf("%d",&sKey);
ITEMshow(STsearch(sKey));
printf("insert counter = %d, search counter = %d\n", cnt1, cnt2);
}
