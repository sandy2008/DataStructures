#include <stdio.h>
#include <stdlib.h>
#include "STitem.h"
STitem NULLitem = {-1, "NULL"};
Key ITEMrand(void){ return rand()%1000; }
int ITEMscan(Key *x){ return scanf("%d", x); }
void ITEMshow(STitem item){
printf("key = %d, info = ", key(item));
puts(info(item));
}
