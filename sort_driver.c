#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int c = 0;

int main(int argc, char *argv[]){
    int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = malloc(N*sizeof(int));
    switch(sw){
        case 0:
        srand(1);
        for (i = 0; i < N; i++)
            a[i] = 1000*(1.0*rand()/RAND_MAX);
    break;
    case 1:
    for (i = 0; i < N; i++) scanf("%d",&a[i]);
    break;
    default:
    for (i = 0; i < N; i++) a[i] = i; break;
}
    sort(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n counter = %d\n",c);
}
