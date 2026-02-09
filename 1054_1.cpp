#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int res=0;
        int n;
        int flag=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                res+=1;
            }
            if(arr[i]==-1){
                flag++;
            }
        }
        flag=flag%2;
        res=res+flag*2;
        cout<<res<<endl;
    }
}