#include<bits/stdc++.h>
using namespace std;

struct Intervals{
    int st;
    int end;
};

bool mycomp(Intervals &a,Intervals &b){
    return (a.st<b.st);
}
void mergeIntervals(Intervals arr[],int n){
    sort(arr,arr+n,mycomp);
    int res=0;

    for(int i=1;i<n;i++){

        if(arr[i].st<=arr[res].end){
            arr[res].st=min(arr[i].st,arr[res].st);
            arr[res].end=max(arr[i].end,arr[res].end);
        }
        else{
            res++;
            arr[res]=arr[i];
        }
    }

    for(int i=0;i<=res;i++){
        cout<<arr[i].st<<" "<<arr[i].end<<endl;
    }
}

int main(){
    int n=6;
    Intervals arr[n];
    cout<<"Enter six intervals"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].st;
        cin>>arr[i].end;
    }
    mergeIntervals(arr,n);
}