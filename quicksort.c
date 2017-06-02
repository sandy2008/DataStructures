#include "sort.h"
extern int c;

int partition(Item a[],int left,int right){
    Item pivot = a[right];
    int i = left-1, j = right-1;
    while(1){
    while(less(a[++i],pivot)) c++;
    while(less(pivot,a[j])){
        j--;
	 c++;
        if( i >= j )
            break;
    }
    if ( i >= j )
    break;
    exch(a[i], a[j]);
    c++;
    }
    c++;
    exch(a[i], a[right]);
    return i;
}

void sort(Item a[],int left,int right){
    int i;
    if (right <= left) return;
    i = partition(a,left,right);
    sort(a,left,i-1);
    sort(a,i+1,right);
}


