#include "PQ.h"

#define MAXN 1000
void main(void){
int a[MAXN], i, k;
srand(1);
for (i = 0; i < MAXN; i++)
a[i] = 1000*(1.0*rand()/RAND_MAX);
PQinit(MAXN);
for (k = 0; k < MAXN; k++) PQinsert(a[k]);
for (k = MAXN-1; k >= 0; k--) a[k] = PQdelmax();
for (i = 0; i < MAXN; i++) printf("%3d ", a[i]);
printf("\n");
}
