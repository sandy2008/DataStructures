#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
#define M 7
int graph[M][M];
int visited[M];

void traverseDF(int start){
    STACKinit(M);
    STACKpush(start);
    int node, next;
    while(STACKempty() == 0){
        node = STACKpop();
        if(visited[node] == 1) continue;
        printf("%d ", node);
        visited[node] = 1;
        for(next = M-1; 0 <= next; next--){
            if(graph[node][next] == 1 && visited[next] == 0)
        STACKpush(next);
        }
    }
}

void main(void){
    int i, j;
    for(i = 0; i < M; i++)
    for(j = 0; j < M; j++)
    graph[i][j] = 0;
    while(scanf("%d %d", &i, &j) == 2)
    graph[i][j] = 1;
    traverseDF(0);
    printf("\n");
}
