#include<bits/stdc++.h>
using namespace std;

class kstack{
    int*arr;
    int * next;
    int * top;
    int freespot;
    
    public:
        kstack(int M,int S){
            int m=M;//no. of stacks
            int s=S;//size of the array
            arr=new int[s];
            top=new int[m];
            next=new int[s];
            //initialize top
            memset(top,-1,m);
            //initialize next
            for(int i=0;i<s;i++){
                next[i]=i+1;
            }
            //initialize freespot to 0
            freespot=0;
        }
    public:
        void push(int x,int m){
            //if stack is full print stack overflow
            if(freespot=-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }

            int index=freespot;
            //change freespot
            freespot=next[index];
            //insert element into stack
            arr[index]=x;
            //change next
            next[index]=top[m-1];
            //change top
            top[m-1]=index;
        }
    public:
        int pop(int m){
            if(top[m-1]==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int index=top[m-1];

            top[m-1]=next[index];

            next[index]=freespot;

            return arr[index];
        }
};