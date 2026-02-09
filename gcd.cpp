#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int a,b;
	cout<<"Enter the values of a and b\n";
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	
}

