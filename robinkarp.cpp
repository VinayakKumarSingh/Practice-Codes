#include<bits/stdc++.h>
using namespace std;

const int d=256;
const int q=101;

void RBSearch(string &txt,string &pat,int M,int N){

    int h=1;

    //calculate d^(m-1) and store it in h use it later
    for(int i=1;i<=M-1;i++){
        h=(h*d)%q;
    }
//calculate initial hash values of text and pattern

    int p=0;
    int t=0;

    for(int i=0;i<M;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }

//compare and print if matched
    
    for(int i=0;i<=N-M;i++){
        if(p==t){
            bool flag=true;
            for(int j=0;j<M;j++){
                if(txt[i+j]!=pat[j]){flag=false; break;}
            }
            if(flag){cout<<i<<" ";}
        }

        if(i<N-M){
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
        }

        if(t<0)
            t=t+q;
    }

}

int main() 
{ 
    string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    cout<<"All index numbers where pattern found:"<<" ";
    RBSearch(txt,pat,4,15);
    cout<<endl;
    return 0; 
} 