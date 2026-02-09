#include<bits/stdc++.h>
using namespace std;

const int CHAR=256;

int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*fact(n-1);
}
int lexicographicRank(string &s){
    vector<int>count(CHAR,0);
    int n=s.length();
    //find frequency of all the elements in the string s
    for(int i=0;i<n;i++){
        count[s[i]]++;
    }
    int mul=fact(n);
    //build cumulative count to find out how many elements less than it is present

    for(int i=1;i<CHAR;i++){
        count[i]+=count[i-1];
    }

    //find the result 

    int res=1;
    for(int i=0;i<n-1;i++){
        mul= mul/(n-i);
        res+=count[s[i]-1]*mul;
    //decrease the frequency once the string is processed 
    for(int j=s[i];j<CHAR;j++)
        count[j]--;
    }
    return res;
}

int main(){
    string s="string";
    cout<<"lexicographical rank is "<<lexicographicRank(s)<<endl;
}