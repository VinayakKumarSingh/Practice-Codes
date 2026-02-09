#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int x){
    data=x;
    prev=NULL;
    next=NULL;
  }
};
int main(){
  Node *head=new Node(10);
  head
  head->next=new Node(20);
  head->next->next = new Node(30);
  
  Node *curr=head;
  while(curr!=NULL){
    printf("%d, ",curr->data);
    curr=curr->next;
  }
  printf("\n");
}
