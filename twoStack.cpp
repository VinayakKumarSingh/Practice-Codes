#include<bits/stdc++.h>
using namespace std;

class TwoStack{
    int *arr;
    int cap,top1,top2;
    public:
        TwoStack(int n){
            arr=new int[n];
            cap=n;
            top1=-1;
            top2=n;
        }
    public:
        bool push1(int item){
            if(top1+1<top2){
                arr[++top1]=item;
                return true;
            }
            else
                return false;
        }
    public:
        bool push2(int  item){
            if(top2-1>top1){
                    arr[--top2]=item;
                    return true;
                }    
            else{
                    return false;
                }
        }
    public:
        int* pop1(){
            if(top1==-1)
                return nullptr;
            else
            {
                int*x=&arr[top1];
                top1--;
                return x;
            }
        }
    public:
        int* pop2(){
            if(top2==cap)
                return nullptr;
            else
            {
                int*x=&arr[top2];
                top2++;
                return x;
            }
        }
    public:
        void printStack1(){
            for(int i=0;i<=top1;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    public:
        void printStack2(){
            for(int i=top2;i>top1;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    TwoStack s(5);
    if(s.push1(23))cout<<"Inserted item int stack 1"<<endl;
    if(s.push2(35))cout<<"Inserted item in stack 2"<<endl;
    if(s.push1(45))cout<<"Inserted item in stack 1"<<endl;
    if(s.push1(56))cout<<"Inserted item in stack 1"<<endl;
    if(s.push2(33))cout<<"Inserted item in stack 2"<<endl;
    if(!s.push1(19))cout<<"Stack overflow "<<endl;
    s.pop1();
    s.pop2();
    s.printStack1();
    s.printStack2();
}