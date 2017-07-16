#define Item int
#define M 7
int graph[M][M];
int visited[M];

void traverseDF_rec(int node){
    printf("%d ",node);
    visited[node] = 1;
    int next;
    for(next = 0; next < M; next++){
        if(graph[node][next] == 1 && visited[next] == 0)
        traverseDF_rec(next);
    }
}

void main(void){
    int i, j;
    for(i = 0; i < M; i++)
    for(j = 0; j < M; j++)
        graph[i][j] = 0;
    while(scanf("%d %d", &i, &j) == 2)
    graph[i][j] = 1;
    for(i = 0; i < M; i++) visited[i] = 0;
    traverseDF_rec(0);
    printf("\n");
}
