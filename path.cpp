#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int x):  data(x),left(nullptr),right(nullptr){}
};
bool findpath(Node* root,vector<Node*>&path,int target){
  if(root==NULL)  return false;
  path.push_back(root);
  if(root->data==target)  return true;
  if(findpath(root->left,path,target)||findpath(root->right,path,target)){
    return true;
  }
  path.pop_back();
  return false;
};

int main(){
  Node* root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->left->left->right=new Node(50);
  root->left->left->right->left=new Node(60);
  
  vector<Node*>path;
  int target=60;
  
  if(findpath(root,path,target))
    for(auto i:path)  cout<<i->data<<"-->";
  cout<<endl;
}
