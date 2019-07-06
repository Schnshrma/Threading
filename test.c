#include<stdio.h>
#include<pthread.h>
void main()
{
 pthread_t id[2];
 void* first(void* args)
{
  for(int i=0;i<9000;i++)
    printf("First thread is executing %d\n",i);
}
void* sec(void* args)
{
  for(int i=0;i<9000;i++)
    printf("second thread %d\n",i);
}
pthread_create(&id[1],NULL,first,NULL);
pthread_create(&id[0],NULL,sec,NULL);
pthread_exit(NULL);
}

