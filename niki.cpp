#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t!=0){
	int n,m;
	cin>>n>>m;
	if(n>=m){
	if(n%2==0)
		if(m%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	else
		if(m%2!=0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	else
		cout<<"NO"<<endl;
	t--;
	}
	return 0;
}
