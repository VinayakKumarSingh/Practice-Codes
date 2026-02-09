#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *prev;
  Node *next;
  Node(int x){
    data = x;
    prev=nullptr;
    next=nullptr;
  }
};

Node* deletetail(Node * head){
  if(head==nullptr) return nullptr;
  if(head->next==nullptr){
    delete(head);
    return nullptr;
  }
  else{
    Node* curr=head;
    while(curr->next->next!=nullptr){
      delete(curr->next);
      curr->next=nullptr;
    }
  }
}
