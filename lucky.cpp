#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	string s;
		cin>>s;
		int len=s.length();
		if(len>2&&s[0]=='1'&&s[1]=='0'){
		s.replace(0,2,"");
		if(!s.empty() && s[0]!='0'){
		if(stoi(s)>=2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;		
	}
	else
		cout<<"NO"<<endl;
	}
	else
		cout<<"NO"<<endl;
}
}
