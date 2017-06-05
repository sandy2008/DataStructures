#include "sort.h"

int findSmallest(Item a[],int left,int right){
    int m = (left + right)/2;
    if (left == right)
        return right;
    int u = findSmallest(a, left, m);
    int v = findSmallest(a, m+1, right);
    if (a[u] > a[v])
        return u;
    else
        return v;
}

void selectionRec(Item a[], int left, int right){
    if(left != right){
        int s = findSmallest(a, left, right);
        exch(a[left], a[s]);
        selectionRec(a, left + 1, right);
    }
}

void insertion(Item a[], int left, int cur){
    if(left != cur){
        if(a[cur - 1] >= a[cur]){
            exch(a[cur - 1],a[cur]);
            insertion(a, left, cur - 1);
        }
    }
}

void isortRec(Item a[], int left, int cur, int right){
    if(cur <= right){
        insertion(a, left, cur);
        isortRec(a, left, cur + 1,right);
    }
}

void insertionRec(Item a[], int left, int right){
    isortRec(a, left, left, right);
}

void bubble(Item a[], int left, int cur){
    if(left != cur){
        compexch(a[cur -1],a[cur]);
        bubble(a, left, cur - 1);
    }
}

void bubblesortRec(Item a[], int left, int right){
    if(left != right){
        bubble(a, left, right);
        bubblesortRec(a, left + 1,right);
    }
}

void sort(Item a[], int left, int right){
    // selectionsortRec(a,left,right);
    // insertionsortRec(a,left,right);
    bubblesortRec(a,left,right);
}
