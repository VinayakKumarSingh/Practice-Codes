#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	int x=0;
	string st;
	cin>>t;
	while(t!=0){
		cin>>st;
		if(st[1]=='+')
			x++;
		else
			x--;
		t--;
	}
	cout<<x<<endl;
}
