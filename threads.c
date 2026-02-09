#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

int a[4][4],b[4][4];

void *matrixeval(void * val){
	int *thno=(int *)val;
	
	for(int i=0;i<4;i++){
			b[(*thno)][i]=a[(*thno)][i];
	}
	
	for(int i=0;i<4;i++){
		//for(int j=0;j<*thno;j++)
			b[(*thno)][i]*=a[(*thno)][i];
	}
	
	printf("[%d] thread \n",(*thno+1));
}

int main(){
	pthread_t tid[4];
	
	for(int i=0;i<4;i++){
		printf("Enter the elements of row %d \n",i+1);
		for(int j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//matrix before evaluation
	printf("Matrix before evaluation : \n");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			printf("%d ",a[i][j]);
			printf("\n");
	}
	for(int i=0;i<4;i++){
		pthread_create(&tid[i],NULL,matrixeval,(void *)&i);
		sleep(1);
	}
	
	for(int i=0;i<4;i++){
		pthread_join(tid[i],NULL);
		sleep(1);
	}
	printf("Matrix after evaluation \n");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			printf("%d ",b[i][j]);
			printf("\n");
	}
	pthread_exit(NULL);
	return 0;
}
