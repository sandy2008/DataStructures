#include "sort.h"
extern int c;

void sort(Item a[], int left, int right){
    int i, j;
    for (i = left; i < right; i++){
    int min = i;
    for (j = i+1; j <= right; j++){
        if (less(a[j], a[min])) min = j;
        c++;
    }
    exch(a[i], a[min]);
    }
}
