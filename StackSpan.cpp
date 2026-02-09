#include<bits/stdc++.h>
using namespace std;

void printstockspan(vector<int>arr){
    int n=arr.size();
    stack<int>s;
    s.push(0);
    cout<<"1 ";
    for(int i =1;i<n;i++){
        while(!s.empty()&&arr[s.top()]<=arr[i])
            s.pop();
        int span=s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}