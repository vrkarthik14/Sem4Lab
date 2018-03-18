#include<stdio.h>
#include<string.h>
#define max 500
int t[max];
void shiftTable(char p[])
{
   int i,j,m;
   m = strlen(p);
   for(i=0;i<max;i++)
     t[i] = m;
   for(j = 0;j<m-1;j++)
     t[p[j]] = m-1-j;
     
   
}

int horsePool(char text[],char p[])
{
   int i,j,k,m,n;
   n = strlen(text);
   m = strlen(p);
   i = m-1;
   while(i<n)
   {
     k = 0;
     while((k<m) && (p[m-1-k]==text[i-k]))
       k++;
     if(k==m)
	return(i-m+1);
     else
  	i = i + t[text[i]];
   }
   return -1;
}

void main()
{
   char text[100],p[100];
   int pos;
   printf("Enter the text\n");
   gets(text);
   printf("Enter the pattern\n");
   gets(p);
   shiftTable(p);
   int i = 0;
   pos = horsePool(text,p);
   if(pos > 0)
     printf("The pattern starts mathcing form %d \n",pos+1);
   else
     printf("The pattern is not found.\n");
}
