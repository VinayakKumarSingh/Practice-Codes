#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(a-b)>=abs(a-c)&&abs(a-b)>=abs(b-c))
		cout<<abs(a-b)<<endl;
	else if(abs(b-c)>=abs(a-b)&&abs(b-c)>=abs(a-c))
		cout<<abs(b-c)<<endl;
	else
		cout<<abs(a-c)<<endl;
	}
}
