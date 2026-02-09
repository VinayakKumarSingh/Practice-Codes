#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next;
  Node(int x){
    data=x;
    prev=NULL;
    next=NULL;
  }
};

Node *reverseDLL(Node *head){
  if(head==NULL || head->next == NULL) return head;
  Node* prev=NULL, *curr=head;
  while(curr!=NULL){
    prev=curr->prev;
    curr->prev=curr->next;
    curr->next=prev;
    curr=curr->prev;
  }
  return prev->prev;
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
  Node *head=new Node(10);
  head->next = new Node(20);
  head->next->prev = head;
  head->next->next = new Node(30);
  head->next->next->prev = head->next;
  head->next->next->next = new Node(40);
  head->next->next->next->prev = head->next->next;

  cout<<"Before Reversing DLL"<<endl;
  printLL(head);
  head=reverseDLL(head);  
  cout<<"After Reversing the DLL"<<endl;
  printLL(head);
}
