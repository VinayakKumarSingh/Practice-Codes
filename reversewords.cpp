#include<bits/stdc++.h>
using namespace std;
void reverse(string &s,int start,int end){
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
void reverseWords(string &str){
    int start=0;

    for(int end=0;end<str.length();end++){
        if(str[end]==' ')
        {
            reverse(str,start,end-1);
            start=end+1;
        }
    }
    reverse(str,start,str.length()-1);
    reverse(str,0,str.length()-1);
}

int main(){
    string s;

    cout<<"Enter a sentence"<<endl;
    getline(cin,s);
    reverseWords(s);
    cout<<"The reversed up sentence is "<<endl<<"\""<<s<<"\""<<endl;
}