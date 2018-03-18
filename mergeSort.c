#include<stdio.h>
#include<time.h>

void merge(int a[],int i1,int j1,int i2,int j2)
{
   int temp[300000];
   int i,j,k=0;
   i=i1,j=i2;
   while(i<=j1&&j<=j2)
   {
     if(a[i]<a[j])
	temp[k++] = a[i++];
     else
	temp[k++] = a[j++];
     }
   while(i <= j1)
     temp[k++] = a[i++];
   while(j <= j2)
     temp[k++] = a[j++];
   for(i=i1,j=0;i<=j2;i++,j++)
     a[i] = temp[j];
}

void mergeSort(int a[],int i,int j)
{
   int mid;
   if(i<j)
   {	
     mid = (i+j)/2;
     mergeSort(a,i,mid);
     mergeSort(a,mid+1,j);
     merge(a,i,mid,mid+1,j);
     }
}

void main()
{ 
   clock_t start,end;
   int n,i,a[300000];
   double tot_time;
   printf("Enter the number of element\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
     a[i] = rand();
   start = clock();
   mergeSort(a,0,n-1);
   end = clock();
   for(i=0;i<n;i++)
      printf("%d  ",a[i]);
   printf("tot:  %lf ",(double)(end-start)/CLOCKS_PER_SEC);
}
