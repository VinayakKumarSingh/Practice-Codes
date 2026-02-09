#include<bits/stdc++.h>
using namespace std;

int distinctSubstring(string &s){
    int n=s.size();
    vector<int>prev(256,-1);
    int i=0;
    int res=0;
    for(int j=0;j<n;j++){
        i=max(i,prev[s[j]]+1);
        int maxlen=j-i+1;
        res=max(res,maxlen);
        prev[s[j]]=j;
    }
    return res;
}

int main()
{
    string s="abacadaef";
    cout<<"longest substring with distinct characters is of length "<<distinctSubstring(s)<<endl;
}