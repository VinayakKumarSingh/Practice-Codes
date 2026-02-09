#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
int getleafsum(Node* root){
    if(root==NULL)  return 0;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    return getleafsum(root->left)+getleafsum(root->right);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->left->right=new Node(90);
    root->left->right->left=new Node(100);

    int sum=getleafsum(root);
    cout<<sum<<endl;
}