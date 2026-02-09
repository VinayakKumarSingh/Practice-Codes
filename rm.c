#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc,char *argv[]){
	int output_fd;
	if(argc!=2){
		printf("usage : rm file \n");
		return 1;
	}
	output_fd=unlink(argv[1]);
	if(output_fd==-1){
		perror("unlink error");
		return 2;
	}
}
