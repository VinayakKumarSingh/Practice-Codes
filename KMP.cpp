#include<bits/stdc++.h>
using namespace std;

void makeLPS(string &s,vector<int>&lps){
    lps[0]=0;
    int i=1;
    int len=0;
    int n=s.length();
    while(i<n){
        if(s[i]==s[len]){
            lps[i]=len+1;
            len++;
        }
        else{
            if(len==0)
                lps[i]=0;
            else{
                len=lps[len-1];
            }
        }
        i++;
    }
}

void KMP(string &txt,string &pat){
    int n=txt.length();
    int m=pat.length();
    vector<int>lps(m);
    makeLPS(pat,lps);
    int i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){i++;j++;}
        if(j==m){cout<<i-j<<" ";j=lps[j-1];}
        else if(i<n&&txt[i]!=pat[j]){
            if(j!=0){j=lps[j-1];}
            else{
                i++;
            }
        }
    }
}

int main(){
    string txt="bobby is a great gay man and is a gay";
    string pat="gay";
    KMP(txt,pat);
    cout<<endl;
}