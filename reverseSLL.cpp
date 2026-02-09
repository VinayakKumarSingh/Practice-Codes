#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int x){
    data=x;
    next=nullptr;
  }
  Node(int x, Node* ptr){
    data=x;
    next=ptr;
  }
};

Node* reverse(Node* head){
  if(head==NULL||head->next==NULL){
    return head;
  }
  Node* rest_head=reverse(head->next);
  Node* rest_tail=head->next;
  rest_tail->next=head;
  head->next=NULL;
  return rest_head;
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
  cout<<"Before Reversing sll"<<endl;
  printLL(head);
  head=reverse(head);  
  cout<<"After Reversing the sll"<<endl;
  printLL(head);
}
