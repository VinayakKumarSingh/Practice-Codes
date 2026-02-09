#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int x){
    data=x;
    next=NULL;
  }
};

Node* segregateEvenOdd(Node* head){
  Node *os=NULL,*oe=NULL,*es=NULL,*ee=NULL;
  
  for(Node* curr=head;curr!=NULL;curr=curr->next){
    int x=curr->data;
    
    if(x%2==0){
      if(es==NULL){
        es=ee=curr;
      }
      else{
      ee->next=curr;
      ee=ee->next;
      }
    }
    else{
      if(os==NULL){
        os=oe=curr;
      }
      else{
      oe->next=curr;
      oe=oe->next;
      }
    }
  }
  if(os==NULL||es==NULL)  return head;
  ee->next=os;
  oe->next=NULL;
  return es;
}

void printLL(Node *head){
  Node * curr=head;
  while(curr!=NULL){
    cout<<curr->data<<" ";
    curr=curr->next;
  }
  cout<<endl;
}
int main(){
  Node*head=new Node(2);
  head->next=new Node(1);
  head->next->next=new Node(3);
  head->next->next->next=new Node(5);
  head->next->next->next->next=new Node(6);
  head->next->next->next->next->next=new Node(4);
  head->next->next->next->next->next->next=new Node(7);
  cout<<"Before"<<endl;
  printLL(head);
  head=segregateEvenOdd(head);  
  cout<<"After"<<endl;
  printLL(head);
}
