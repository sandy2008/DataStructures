#include <stdio.h>

int record[6][5];
int c;

int path(int x, int y){
    c++;
    if (x == 0 || y == 0) return 1;
    if (record[x][y] == 0){
        record[x][y] = path(x-1,y) + path(x,y-1);
	return path(x-1,y) + path(x,y-1);
}
    else
	return record[x][y];
}

void main(void){
    int num = path(5,4);
    printf("path = %d, counter = %d",num,c);
}