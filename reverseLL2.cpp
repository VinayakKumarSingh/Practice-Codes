#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int x){
    data=x;
    next=NULL;
  }
  Node(int x,Node* ptr){
    data=x;
    next=ptr;
  }
};

Node* reversegroup(Node* head,int l,int r){
  Node* dummy=new Node(0,head);
  Node* prevLeft=dummy,*curr=head;
  for(int i=1;i<l;i++){
    prevLeft=curr;
    curr=curr->next;
  }
  Node* prev=NULL;
  for(int i=1;i<=r-l+1;i++){
    Node* tempnext=curr->next;
    curr->next=prev;
    prev=curr;
    curr=tempnext;
  }
  
  prevLeft->next->next=curr;
  prevLeft->next=prev;
  
  return dummy->next;
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
  int left,right;
      Node*head=new Node(1);
     /*head->next=new Node(2);
      head->next->next=new Node(3);
      head->next->next->next=new Node(4);
      head->next->next->next->next=new Node(5);
      head->next->next->next->next->next=new Node(6);*/
      cout<<"Enter the values of left and right"<<endl;
      cin>>left>>right;
      cout<<"Before Reversing sll"<<endl;
      printLL(head);
      head=reversegroup(head,left,right);  
      cout<<"After Reversing the sll"<<endl;
      printLL(head);
}
