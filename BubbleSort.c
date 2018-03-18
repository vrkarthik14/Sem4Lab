#include<stdio.h>
#include<time.h>

void main()
{
   int a[300000],n,temp,i,j;
   clock_t start,end;
   printf("Enter the number of elements\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
     a[i] = rand();
   start = clock();
   for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-1-i;j++)
      {
	if(a[j]>a[j+1])
	{
	  temp = a[j];
	  a[j] = a[j+1];
   	  a[j+1] = temp;
	}
      }
   }
   end = clock();
   for(i = 0;i<n;i++)
     printf("%d  ",a[i]);
   printf("Total time : %lf",(double)(end-start)/CLOCKS_PER_SEC);
}
