#include<iostream>
using namespace std;
void isSet(int n, int k){
	int x=(1<<(k-1));//returns 2^k-1
	if(n&x!=0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
int main(){
	int n,k;
	cout<<"Enter the number and kth bit to check"<<endl;
	cin>>n>>k;
	isSet(n,k);
}
