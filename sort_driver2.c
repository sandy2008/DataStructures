#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int c = 0;

void main(int argc, char *argv[]){
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
    clock_t start = clock();//Timer Start
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    clock_t end = clock(); //Timer End
    printf("\n counter = %d\n",c);
    float seconds = (float)(end - start);
    printf("time = %.3lf\n",seconds);
}
