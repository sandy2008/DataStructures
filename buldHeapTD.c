#include <stdio.h>
#include <string.h>
#include "sort.h"


#define exch(A, B) { Item t = A; A = B; B = t; }
#define more(A, B) (A > B)

void fixUp(Item a[], int k, int N){
int j;
while (2*k <= N){
j = 2*k;
if (j < N && more(a[j], a[j+1])) j++;
if (!more(a[k], a[j])) break;
exch(a[k], a[j]); k = j;
}
}

void insertHeap(Item heap[], int n, Item v){
    heap[++n] = v;
    fixUp(heap, n, n+1);
}

void buildHeapTD(Item a[], int N){
int i;
for(i = 0; i <= N; i++)
    insertHeap(a,i,a[i]);
 }

void main(int argc, char* argv[]){
    int N = strlen(argv[1]);
    Item heap[N+1];
    int i;
    for(i = 0; i <= N-1; i++){ heap[i+1] = argv[1][i]; }
    buildHeapTD(heap, N);
    for(i = 1; i <= N; i++) { printf("%c ", heap[i]); }
    printf("\n");
    return;
}
