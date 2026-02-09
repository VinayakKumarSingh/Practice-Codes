#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	
	while(t!=0){
	char s[101];
	cin>>s;
	if(strlen(s)>10){
	cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;
	}
	else
	cout<<s<<endl;
	t--;
	}
}
