#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    int c=0;
    if(freq.count(k))
        c=freq[k];
    
    int z=0;
    for(int i=0;i<k;i++){
        if(freq.count(i)==0){
            z++;
        }
    }
    cout<<max(z,c)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}