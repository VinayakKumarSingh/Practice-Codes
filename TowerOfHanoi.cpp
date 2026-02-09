#include<iostream>
#include<string>
using namespace std;
void TOH(int,char,char,char);
int main(){
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	char A='A',B='B',C='C';
	TOH(n,A,B,C);
}
void TOH(int n,char A,char B,char C){
	if(n==1){
		cout<<"Move tower "<< n<<" from "<<A<<" to "<<C<<endl;
		return;
	}
	TOH(n-1,A,C,B);
	cout<<"Move tower "<< n<<" from "<<A<<" to "<<C<<endl;
	TOH(n-1,B,A,C);
}
