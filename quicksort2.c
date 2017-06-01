#include "sort.h"
extern int c;

void sort(Item a[],int left,int right){
    int i;
    if(right - left >9){
    if (right <= left) return;
    i = partition(a,left,right);
    sort(a,left,i-1);
    sort(a,i+1,right);
    }
    else insertion(a,left,right);
}

int partition(Item a[],int left,int right){
    Item pivot = a[(left+right)/2];
    int i = left-1, j = right-1;
    while(1){
    while(less(a[++i],pivot));
    while(less(pivot,a[j])){
        j--;
        if( i >= j )
            break;
    }
    if ( i >= j )
        break;
    exch(a[i], a[j]);
    }
    exch(a[i], a[right]);
    return i;
}

void insertion(Item a[], int left, int right){
    int i;
    for (i = left + 1;i <= right; i++){
        int j = i;
        Item v = a[i];
        c++;
        while (less(v,a[j-1]) && left < j){
            c++;
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
        }
}
