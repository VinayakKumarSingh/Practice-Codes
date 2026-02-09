#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define bufsize 10

pthread_mutex_t mutex;
sem_t empty,full;
int buffer[bufsize];
pthread_t tidC[20],tidP[20];
int count;

void initialise(){
	sem_init(&empty,0,bufsize);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	count =0;
}

void write1(int item){
	buffer[count++]=item;
}

int read1(){
	return (buffer[--count]);
}
void *producer(void *param){
	int item;
	item=rand()%5;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	
	printf("Producer produced item %d \n",item);
	write1(item);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void *consumer(void *param){
	int item;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	
	item=read1();
	printf("Consumer consumed item %d \n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

int main(){
	initialise();
	int n1,n2;
	printf("Enter the no.of producers and consumeres| \n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	for(int i=0;i<n1;i++){
		pthread_create(&tidP[i],NULL,producer,NULL);
	}
	for(int i=0;i<n2;i++){
		pthread_create(&tidC[i],NULL,consumer,NULL);
	}
	for(int i=0;i<n1;i++)
		pthread_join(tidP[i],NULL);
	for(int i=0;i<n2;i++)
		pthread_join(tidC[i],NULL);
		
	exit(0);
}
