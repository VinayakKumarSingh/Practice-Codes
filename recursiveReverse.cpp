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

  Node* reverse(Node* curr,Node* prev){
    if(curr==NULL)
      return prev;
    Node* next=curr->next;
    curr->next=prev;
    return reverse(next,curr);
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
    Node* curr=head;
    Node* prev=NULL;
    
    head=reverse(curr,prev);  
    cout<<"After Reversing the sll"<<endl;
    printLL(head);
  }
