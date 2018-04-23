#include<stdio.h>
#include<string.h>

 
// visited array
int N;
int visited[10];
int graph[10][10];
int front = 0;
int rear = 0;
int q[10] = { 0 };
 
void bfs(int v);
 
int main() {
    int i,j;
    printf("Enter number of vertices\n");
    scanf("%d",&N);
     printf("\nEnter adjecency matrix of the graph:");
   
    for(i=0;i<N;i++)
       for(j=0;j<N;j++)
            scanf("%d",&graph[i][j]);
     
    
    // make all vertex unvisited this function set all to a value - in strin.h
    memset(visited, 0, sizeof(visited));
 
    // run bfs from 0th vertex
    bfs(0);
    return 0;
}
 
void bfs(int v) {
 
    // make vertex v visited
    visited[v] = 1;
    // enqueue vertex v
    q[rear] = v; // insert at rear
    rear++; // increment rear
 
    while (rear != front) // condition for empty queue
    {
        // dequeue
        int u = q[front];
        printf("%d ", u);
        front++;
 
        // check adjacent nodes from u
        int i = 0;
        for (i = 0; i < N; i++) {
            // if there is adjacent vertex enqueue it
            if (!visited[i] && graph[u][i]) {
                q[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
