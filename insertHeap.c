#include <stdio.h>
typedef char Item;
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

void main(void){
    int i, j;
    Item input[] = "ALGORITHM";
    Item heap[9];
    for(i=0; i<9; i++){
        printf("Insert %c : ", input[i]);
        insertHeap(heap, i, input[i]);
    for(j = 1; j <= i+1; j++){ printf("%c", heap[j]); }
        printf("\n");
    }
}
