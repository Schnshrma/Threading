#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define no_of_threads rows
#define rows 5
#define colls 5

int sum[no_of_threads];
int a[rows][colls];
void *matsum(void *args)
{
 int no=*(int*)args;
for(int j=no;j<rows;j+=no_of_threads) 
   for(int it=0;it<colls;it++)
      sum[no]+=a[j][it];
return NULL;
}
void main()
{ 
 pthread_t tid[no_of_threads];
 printf("Enter the elements of matrix");
 for(int i=0;i<rows;i++)
   for(int j=0;j<colls;j++)
       scanf("%d",&a[i][j]);
 int pass[]={0,1,2,3,4,5,6,7,8,9,10};   // maximum 10 threads can be created 
  for(int i=0;i<no_of_threads;i++)
      pthread_create(&tid[i],NULL,&matsum,&pass[i]);   
  for(int k=0;k<no_of_threads;k++)
   {
     pthread_join(tid[k],NULL);
     printf("\n Sum of row %d is %d ",k,sum[k]);
    }    
 
}
    
