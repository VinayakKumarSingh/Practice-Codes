#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int res=0;
    vector<int>arr(n);
    for(int a=0;a<n;a++){
        cin>>arr[a];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i=i+2){
        if(arr[i+1]-arr[i]>res){
            res=arr[i+1]-arr[i];
        }
    }
    cout<<res<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
}
}