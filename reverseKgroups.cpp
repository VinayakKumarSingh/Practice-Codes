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
Node* reversegroup(Node* head,int k){
  Node* curr=head;
  Node* prev=NULL,*nextn=NULL;
  int count=0;
  while(curr!=NULL && count<k){
    nextn=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextn;
    count++;
  }
  if(nextn!=NULL){
    Node* rem_head=reversegroup(curr,k);
    head->next=rem_head;
  }
  return prev;
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
      Node*head=new Node(10);
      head->next=new Node(20);
      head->next->next=new Node(30);
      head->next->next->next=new Node(40);
      head->next->next->next->next=new Node(50);
      head->next->next->next->next->next=new Node(60);
      cout<<"Before Reversing sll"<<endl;
      printLL(head);
      head=reversegroup(head,3);  
      cout<<"After Reversing the sll"<<endl;
      printLL(head);
}
