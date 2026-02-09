#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define N 5
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N

int phil[N]={0,1,2,3,4};
int state [N];
sem_t mutex;
sem_t S[N];

void test(int phnum){
	if(state[phnum]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
		
		state[phnum]=EATING;
		sleep(2);
		printf("%d philospher took fork %d and %d \n",phnum+1,LEFT+1,phnum+1);
		printf("%d philosher is eating \n",phnum +1);
		sem_post(&S[phnum]);//declaring phnum is free
	}
}

void take_fork(int phnum){
	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("%d philospher is hungry \n",phnum+1);
	test(phnum);
	sem_wait(&S[phnum]);
	sem_post(&mutex);
}

void put_fork(int phnum){
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("Philospher %d kept fork %d and %d\n",phnum+1,LEFT+1,phnum+1);
	printf("Philospher %d is thinking\n",phnum+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *philospher(void *value){
	while(1){
		int *i=value;
		sleep(1);//thinking
		take_fork(*i);
		sleep(0);//eating
		put_fork(*i);
	}
}

int main(){
	pthread_t TID[5];
	//semaphore initialisaiton
	sem_init(&mutex,0,1);
	for(int i=0;i<N;i++)
		sem_init(&S[i],0,0);
	
	for(int i=0;i<N;i++){
		pthread_create(&TID[i],NULL,philospher,&phil[i]);
		printf("philosher %d is thinking\n",i+1);
	}
	
	for(int i=0;i<N;i++){
		pthread_join(TID[i],NULL);
	}
}
