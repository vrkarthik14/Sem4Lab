#include<stdio.h>
#include<time.h>
void main()
{
   int a[300000],i,j,min,n,temp;
   clock_t start,end;
   printf("enter the number of elemnt\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
     a[i] = rand();
   start = clock();
   for(i=0;i<n-1;i++)
   {
     min = i;
     for(j=i+1;j<n;j++)
     {
	if(a[j] < a[min])
	  min = j;
     }
     temp = a[min];
     a[min] = a[i];
     a[i] = temp;
   }
   end = clock();
   for(i=0;i<n;i++)
     printf("%d  ",a[i]);
   printf("tim taken :%lf",(double)(end-start)/CLOCKS_PER_SEC);
}
