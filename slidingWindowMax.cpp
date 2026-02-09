#include<bits/stdc++.h>
using namespace std;
void printmaxAllsubarray(int arr[],int n,int k){
    deque<int>dq;
    for(int i=0;i<k;i++){
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty()&&dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;

}
int main(){
    int n,k;
    n=8;
    k=3;
    int arr[8]={1,3,-1,-3,5,3,6,7};
    printmaxAllsubarray(arr,n,k);
}