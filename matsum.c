#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define rows 5
#define colls 5
#define no_of_threads 2
int sum[rows];
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
{ int sumf=0;
 pthread_t tid[no_of_threads];
 printf("Enter the elements of matrix");
 for(int i=0;i<rows;i++)
   for(int j=0;j<colls;j++)
       scanf("%d",&a[i][j]);
 int pass[]={0,1,2,3,4,5,6,7,8,9,10};
  for(int i=0;i<no_of_threads;i++)
      pthread_create(&tid[i],NULL,&matsum,&pass[i]);   
  for(int k=0;k<no_of_threads;k++)
   {
     pthread_join(tid[k],NULL);
     sumf+=sum[k];
    }    
  printf("\nSum of arr= %d",sumf);
}
    
