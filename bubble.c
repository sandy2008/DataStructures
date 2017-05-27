#include "sort.h"
extern int c;

void sort(Item a[], int left, int right){
    int i, j;
    for (i = left; i < right; i++)
    for (j = right; j > i; j--){
        compexch(a[j-1], a[j]);
        c++;
    }
}
