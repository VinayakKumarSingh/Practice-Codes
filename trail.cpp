#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int res=0;
	for(int i=5;i<n;i=i*5){
	res+=(n/i);
	}
	cout<<res<<endl;
}
