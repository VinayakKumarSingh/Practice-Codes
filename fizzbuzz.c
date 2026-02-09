#include<stdio.h>
#include<string.h>
void fizzbuzz(int num){
	char s[10];
	if(num%3==0)
		strcat(s,"fizz");
	if(num%5==0)
		strcat(s,"Buzz");
	printf("%s",s);
}
int main(){
	int num;
	printf("Enter the number");
	scanf("%d",&num);
	fizzbuzz(num);
}
