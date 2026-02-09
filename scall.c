#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<wait.h>
#include<string.h>
int main(int argc,char *argv[]){
	printf("Main Program \n");
	int retval=1;
	pid_t PID =fork();
	
	if(PID<0){
		printf("Error creating a child process");	
	}
	if(PID==0){
		printf("The child process is %d \n The parent process is %d \n",getpid(),getppid());
		execl("./hello",argv[1],NULL);
	}
	else{
		printf("The parent process is %d \n",getpid());
		wait(&retval);
		
		if(WIFEXITED(retval)==1){
			printf("The child terminated normally \n");
		}
		else{
			printf("The child terminated abnormally \n");
			exit(0);
		}
	}
	return 0;
}
