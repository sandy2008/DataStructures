#include <stdio.h>

int sum(int a[], int down, int up){
    printf("sum(%d,%d) is called\n", down, up);
    avg = (down + up)/2;
    if(avg = down)
	return down;
    else
        return sum(a,down,avg)+sum(a,avg+1,up);

}

void main(int argc, char* argv[]){
    int i, N = argc-1;
    int a[N];
    for(i = 0; i < N; i++){
    a[i] = atoi(argv[i+1]);
}
    printf("sum = %d\n", sum(a,0,N-1));
}
