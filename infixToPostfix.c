#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
	if(top==MAX-1){
		printf("Stack Overflow \n");
		return;
	}
	stack[++top]=c;
}
char pop(){
	if(top==-1){
		printf("Stack underflow \n");
		return -1;
	}
	return stack[top--];
}
char peek(){
	return stack[top];
}

int isOperator(char c){
	return(c=='+'||c=='-'|| c=='*'|| c=='/');
}

int precedence(char c){
	if(c=='*'||c=='/')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	return 0;
}

void infixtopostfix(char *infix,char *postfix){
	int i=0,j=0;
	char token;
	
	while((token=infix[i++])!='\0'){
		if(isalnum(token))
			postfix[j++]=token;
		else if(token=='(')
			push(token);
		else if(token==')'){
			while(top!=-1 && peek()!='('){
				postfix[j++]=pop();
			}
			pop();//pop (
		}
		else if(isOperator(token)){
			while(top!=-1 && precedence(token)<=precedence(peek())){
				postfix[j++]=pop();
			}
			push(token);
		}
	}
	while(top!=-1){
			postfix[j++]=pop();
		}
		postfix[j]='\0';
}

int main(){
	char infix[MAX];
	char postfix[MAX];	
	printf("Enter the infix Expression \n");
	fgets(infix,MAX,stdin);
	infixtopostfix(infix,postfix);
	puts(postfix);
	return 0;
}
