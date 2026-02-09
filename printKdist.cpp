#include<bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node* left;
  node* right;
  
  node(int k){
    key=k;
  }
};

void printkdist(node* root,int k){
  if(root==NULL||k<0)
    return;
  if(k==0)
    cout<<root->key<<" ";
  else{
    printkdist(root->left,k-1);
    printkdist(root->right,k-1);
  }
}
int main(){
  node *root=new node(10);
  root->left=new node(20);
  root->right=new node(30);
  root->left->left=new node(40);
  root->left->right=new node(90);
  root->right->left=new node(50);
  root->right->right=new node(60);
  printkdist(root,2);
  cout<<endl;
}
