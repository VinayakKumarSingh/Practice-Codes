#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double a,b;
		cin>>a>>b;
		int q=ceil(a/b);
		int res=(b*q)-a;
		cout<<res<<endl;
	}
}
