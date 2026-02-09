#include<bits/stdc++.h>
#include<cctype>
using namespace std;

int main(){
  map<char,int> vowelFreq,consFreq;
  string s="aeiou i love titty 123";
  string vowel="aeiou";
  
  for(char ch:s){
    if(isalpha(ch)){
      ch=tolower(ch);
        if(vowel.find(ch)!=string::npos){
          vowelFreq[ch]++;
        }
        else{
          consFreq[ch]++;
        }
    }
  }
  
  int maxfreqVowel=0;
  
  for(auto p:vowelFreq){
    if(p.second>maxfreqVowel){
      maxfreqVowel=p.second;
    }
  }
  int maxfreqConst=0;
  for(auto p:consFreq){
    if(p.second>maxfreqConst){
      maxfreqConst=p.second;
    }
  }
  cout<<maxfreqVowel+maxfreqConst<<endl;
}
