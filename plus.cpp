#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t!=0){
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b==c)
		cout<<'+';
	else
		cout<<'-';
	t--;
	cout<<endl;
	}
	return 0;
}
