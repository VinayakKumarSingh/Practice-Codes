#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		float n,x;
		cin>>n>>x;
		if(n==1.0||n==2.0){
			cout<<1<<endl;
		}
		else
			cout<<ceil((n-2.0)/x)+1<<endl;
	}
}
