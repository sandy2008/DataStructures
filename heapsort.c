#include "sort.h"

extern int c;
void fixDown(Item a[], int k, int N){
int j;
while (2*k <= N){
j = 2*k;
if (++c && j < N && less(a[j], a[j+1])) j++;
if (++c && !less(a[k], a[j])) break;
exch(a[k], a[j]);
k = j;
}
}
void sort(Item a[], int l, int r){
int k, N = r-l+1;
Item* heap = a+l-1;
for (k = N/2; k >= 1; k--)
fixDown(heap, k, N);
while (N > 1){
exch(heap[1], heap[N]);
fixDown(heap, 1, --N);
}
}
