#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
  node(int x){
    data=x;
    next=nullptr;
  }
};

void printcll(node *head){
  if(head==nullptr){
    cout<<" "<<endl;
    return;
  }
  node *curr=head;
  do{
    cout<<curr->data<<" ";
    curr=curr->next;
  }while(curr!=head);
  cout<<endl;
}

node *insertatend(node *head,int x){
  node *temp=new node(x);
  if(head==nullptr){
    temp->next=temp;
    return temp;
  }
  else{
    temp->next=head->next;
    head->next=temp;
    swap(head->data,temp->data);
    return temp;
  }
}

int main(){
  node *head=nullptr;
  head=insertatend(head,10);
  head=insertatend(head,12);
  head=insertatend(head,330);
  printcll(head);
}
