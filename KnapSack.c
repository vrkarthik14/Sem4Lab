#include<stdio.h>

int max(int x,int y)
{
return(x>y)?x:y;
}

void knapsack(int m,int n,int w[],int p[]){

int v[100][200],x[10],i,j,sum=0;

for(i=0;i<=n;i++) //filling first row and column with zeros
v[i][0]=0;
 for(j=0;j<=m;j++)
v[0][j]=0;

for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(j>=w[i])
v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]); 
else
v[i][j]=v[i-1][j];
}
}


for(i=1;i<=n;i++)
x[i]=0;
i=n;
j=m;
while(i>0 && j>0)
{
if(v[i][j]!=v[i-1][j]) 
{
x[i]=1;
j=j-w[i];
}
i--;
}
printf("the optimal set of items is\n");
for(i=1;i<=n;i++)
{
if(x[i]==1)
{
printf("%d\t",i);
sum=sum+p[i];
}
}
printf("total profit is=%d",sum);
}





void main(){
int w[10],p[10],m;
int i,n,j;
printf("enter the number of elenmts\n");
scanf("%d",&n);
printf("enter the weights\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter the profit values of the items\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter the capacity\n");
scanf("%d",&m);
knapsack(m,n,w,p);

}
