#include<stdio.h>
 
void DFS(int);
int G[15][15],visited[15],n;    //n is no of vertices and graph is sorted in array G[10][10]
 
void main()
{
    int i,j,sou;
    printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
   
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
        
   printf("Enter source of search from 0 to n-1");
   scanf("%d",sou)     
   DFS(sou);
 
   for(i=0;i<n;i++)
       if(visited[i] == 0)
         DFS(i);
}
 
void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
