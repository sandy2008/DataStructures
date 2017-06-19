#include <stdio.h>
#include <string.h>
#include "sort.h"


#define exch(A, B) { Item t = A; A = B; B = t; }
#define less(A, B) (A < B)

void fixUp(Item a[], int k){
    while (k > 1 && less(a[k/2], a[k])){
        exch(a[k], a[k/2]); k = k/2;
    }
}

void insertHeap(Item heap[], int n, Item v){
    heap[++n] = v;
    fixUp(heap, n);
}

void buildHeapTD(Item a[], int N){
    int i;
    for(i = 1; i <= N; i++)
    insertHeap(a, i-1 ,a[i]);
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
