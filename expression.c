#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	char info;
	struct node * left;
	struct node * right;
};
typedef struct node * NODE;

struct stack{
	NODE data[20];
	int top;
};
typedef struct stack * STACK;

NODE getnode(char c){
	NODE temp=(NODE)malloc(sizeof(struct node));
	temp->info=c;
	temp->left=temp->right=NULL;
	return temp;
}

void push(STACK s,NODE n){
	s->data[++(s->top)]=n;
}

NODE pop(STACK s){
	return s->data[(s->top)--];
}

void inorder(NODE root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c  ",root->info);
		inorder(root->right);
	}
}

int preced(char c){
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
}

NODE infixtoExp(char * infix){
	STACK tree=(STACK) malloc(sizeof(struct stack));
	STACK op=(STACK) malloc(sizeof(struct stack));
	
	tree->top=-1;
	op->top=-1;
	
	NODE t,l,r;
	for(int i=0;infix[i]!='\0'&&infix[i]!='\n';i++){
		char token=infix[i];
		
		NODE temp=getnode(token);
		
		if(isalnum(token))
			push(tree,temp);
		else{
			if(op->top==-1)
				push(op,temp);
			else{
				while(op->top!=-1 && preced(op->data[op->top]->info)>=preced(token)){
					t=pop(op);
					r=pop(tree);
					l=pop(tree);
					
					t->right=r;
					t->left=l;
					
					push(tree,t);
				}
				
				push(op,temp);
			}
		}
		
	}
	while(op->top!=-1){
		t=pop(op);
		r=pop(tree);
		l=pop(tree);
		t->right=r;
		t->left=l;
		push(tree,t);
	}
	pop(tree);
}
int main(){
	char infix[20];
	fgets(infix,20,stdin);
	NODE root=NULL;
	root=infixtoExp(infix);
	printf("Inorder\n");
	inorder(root);
}
