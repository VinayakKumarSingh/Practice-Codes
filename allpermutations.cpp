#include<iostream>
#include<string>
using namespace std;
void permute(string s,int i);
int main(){
	string s;
	getline(cin,s);
	int index=0;
	permute(s,index);
}
void permute(string s,int i){
	if(i==s.length()-1){
		cout<<s<<endl;
		return;
	}
	for(int j=i;j<s.length();j++){
		int t=0;
		t=s[i];
		s[i]=s[j];
		s[j]=t;
		permute(s,i+1);
		t=s[i];
		s[i]=s[j];
		s[j]=t;
	}
}
