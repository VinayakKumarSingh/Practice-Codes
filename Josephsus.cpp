#include<iostream>
using namespace std;
int jos(int,int);
int main(){
	int n,k;
	cout<<"Enter the Number of People and the Kth person to kill"<<endl;
	cin>>n>>k;
	cout<<"The person alive is "<<jos(n,k)+1<<endl;
}
int jos(int n,int k){
	if(n==1)
		return 0;
	else
		return (jos(n-1,k)+k)%n;
}
