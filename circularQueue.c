#include<stdio.h>
#define cap 15

int queue [cap];
int front =-1;
int rear =-1;

int isFull(){
	return ((rear+1)%cap==front);
}
int isEmpty(){
	return (front==-1);
}

void enqueue(int data){
	if(isFull()){
		printf("The Queue is full \n");
		return;
	}
	if(front==-1)
		front=0;
	
	rear=(rear+1)%cap;
	queue[rear]=data;
	printf("Queue is inserted \n");
}

int dequeue(){
	if(isEmpty()){
		printf("The Queue is Empty \n");
		return -1;
	}
	int data=queue[front];
	
	
	front=(front+1)%cap;
	
	if(front==rear)
		front=rear=-1;
	
	//printf("The element is deleted\n");
	
	return data;
}

void display(){
	if(isEmpty()){
		printf("The queue is empty \n");
		return;
		}
	printf("Queue elements are \n");
	int i=front;
	while(i!=rear){
		printf("%d ",queue[i]);
		i=(i+1)%cap;
	}
	
	printf("%d\n",queue[rear]);
}

int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printf("Add elements in the array \n");
	for(int i=0;i<12;i++){
		int d;
		scanf("%d",&d);
		enqueue(d);
	}
	display();
	printf("Dequeued element is %d \n",dequeue());
	enqueue(1000);
	display();
}
