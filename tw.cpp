#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<01<<endl;
	}
	if(n==1){
		cout<<05<<endl;
	}
	else if(n>1)
		cout<<25<<endl;
}
