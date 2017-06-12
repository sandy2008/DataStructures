#include "sort.h"

#define min(A,B) (A < B) ? A : B

void merge(Item a[], int left, int mid, int right){
    int N = right-left+1, i;
    Item temp[N];
    mergeAB(temp,a+left,mid-left+1,a+mid+1,right-mid);
    for (i=0; i<N; i++){
            a[left+i] = temp[i];
    }
}

void mergesortBU(Item a[],int left,int right){
    int i, m;
    for (m = 1; m < right-left; m = m+m)
        for (i = left; i <= right-m; i += m+m)
            merge(a, i, i+m-1, min(i+m+m-1, right));
}
