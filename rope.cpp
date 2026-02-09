#include<iostream>
#include<algorithm>
using namespace std;
int divide(int n,int a,int b,int c){
	if(n==0)
		return 0;
	if(n<0)
		return -1;
	int res=max({divide(n-a,a,b,c),divide(n-b,a,b,c),divide(n-c,a,b,c)});
	if(res==-1)
		return -1;
	else
		res=res+1;
	return res;
}
int main(){
	int n,a,b,c;
	cout<<"Enter the value of n,a,b and c"<<endl;
	cin>>n>>a>>b>>c;
	if(divide(n,a,b,c)>0)
	cout<<"Maximum Pieces are "<<divide(n,a,b,c)<<endl;
	else
	cout<<"Not possible"<<endl;
}
