#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max=-1;
	int secmax=-1;
	int min=11111;
	int secmin=11111;
	
	for(int i=0;i<n;i++){
		if(a[i]>max){
				secmax=max;
				max=a[i];
		}
		if(a[i]>secmax&&a[i]<max){
			secmax=a[i];
		}
	
		if(a[i]<min){
				secmin=min;
				min=a[i];
		}
		if(a[i]<secmin&&a[i]>min){
			secmin=a[i];
		}
	}
	printf("The second largest and second smallest are %d and %d respectively \n",secmax,secmin);
}
