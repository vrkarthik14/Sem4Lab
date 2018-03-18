#include<stdio.h>
#include<time.h>

int find_pivot(int arr[],int start,int end)
{
   int pivot =start;
   int l = start + 1;
   int r = end;
   int temp;
   while(l<=r)
   {
     if(arr[l]>=arr[pivot] && arr[r]<=arr[pivot])
     {
	temp = arr[l];
	arr[l++] = arr[r];
	arr[r--] = temp; 
      }
     else if(arr[r]>arr[pivot]) r--;
     else l++;
   }
   temp = arr[pivot];
   arr[pivot] = arr[r];
   arr[r] = temp;
   return r;
}

void quickSort(int arr[],int start,int end)
{
   if(start<end)
   {
     int pivot = find_pivot(arr,start,end);
     quickSort(arr,start,pivot-1);
     quickSort(arr,pivot+1,end);
   }
}

void main()
{
   int i,n,arr[30000];
   clock_t start,end;
   printf("Enter number of element\n");
   scanf("%d",&n);
   for(i = 0;i<n;i++)
      arr[i] = rand();
   start = clock();
   quickSort(arr,0,n-1);
   end = clock();
   for(i = 0;i<n;i++)
      printf("%d  ",arr[i]);
   printf("Time taken is  %lf",(double)(end-start)/CLOCKS_PER_SEC);
}
