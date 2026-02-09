#include<iostream>
using namespace std;
int sum(int num){
	if(num==0)
		return 0;
	else
		return sum(num/10)+num%10;
}
int main(){
	int num;
	cin>>num;
	cout<<sum(num)<<endl;
}
