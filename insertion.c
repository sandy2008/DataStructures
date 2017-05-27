#include "sort.h"
extern int c;

void sort(Item a[], int left, int right){
    int i;
    for (i = left + 1;i <= right; i++){
        int j = i;
        Item v = a[i];
        c++;
        while (less(v,a[j-1]) && left < j){
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
        }
}
