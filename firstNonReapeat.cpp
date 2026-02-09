#include<bits/stdc++.h>
#include<limits>
using namespace std;

const int CHAR = 256;

int firstNonReapeat(string &s){
    vector<int>findex(CHAR,-1);

    for(int i=0;i<s.length();i++){
        if(findex[s[i]]==-1){
            findex[s[i]]=i;
        }
        else{
            findex[s[i]]=-2;
        }
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(findex[i]>0){
            res=min(res,findex[i]);
        }
    }
    if(res<s.length())
        return res;
    else 
        return -1;
}

int main(){

    string s="aabbcdd";

    cout<<"First non repeating character is "<<"at position "<<firstNonReapeat(s)<<" and the character is "<<s[firstNonReapeat(s)]<<endl;
}