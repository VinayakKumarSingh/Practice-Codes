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

Node* findkthNode(Node* temp,int k){
  k=k-1;
    while(temp&&k>0){
      temp=temp->next;
      k--;
    }
    return temp;
}

Node* reverse(Node* head){
  Node* curr=head,*prev=NULL;
  while(curr!=NULL){
    Node* next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  return prev;
}

Node* reversegroup(Node* head,int k){
  Node* temp=head,*nextnode,*prevnode;
  while(temp!=NULL){
    Node* kthnode=findkthNode(temp,k);
    if(kthnode==NULL){
      if(prevnode){
        prevnode->next=temp;
      }
    break;
    }
    nextnode=kthnode->next;
    kthnode->next=NULL;
    reverse(temp);
    if(temp==head){
      head=kthnode;
    }
    else{
      prevnode->next=kthnode;
    }
    prevnode=temp;
    temp=nextnode;
  }
  return head;
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
