#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
//#include<Sys/types.h>
#define max 10
#define no_of_threads 4
int summ[no_of_threads];
int a[max];
void *sum(void *arg)
{
 int thread_no=*(int*)arg;
 int i;
 
 for(i=thread_no;i<max;i+=no_of_threads)
{ summ[thread_no]+=a[i];
printf("\n Thread number %d doing sum of :a[%d]",thread_no,i);

}
printf("Sum done by thread %d is %d",thread_no,summ[thread_no]);
return NULL;
}
void main()
{
 pthread_t tid[no_of_threads];
 int sumf=0;
 printf("Enter the all %d elements of thread =",max);
 for(int j=0;j<max;j++)
   scanf("%d",&a[j]);
int pi[]={0,1,2,3};
for(int p=0;p<no_of_threads;p++)
  pthread_create(&tid[p],NULL,sum,(void*)&pi[p]);
for(int k=0;k<no_of_threads;k++){
  pthread_join(tid[k],NULL);
   sumf+=summ[k];}
printf("Sum of your array is %d",sumf);
}
