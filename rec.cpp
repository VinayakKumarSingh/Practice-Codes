#include<iostream>
using namespace std;
void rec(int n){
	if(n==0)
		return;
	rec(n-1);
	cout<<n;
}
int main(){
	int n;
	cout<<"Enter the number : "<<endl;
	cin>>n;
	//cout<<"The binary equivalent is : ";
	rec(n);
	cout<<endl;
}
