#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int a[5][5];
	int res;
	int i,j;
	for(int k=0;k<5;k++)
		for(int l=0;l<5;l++){
			cin>>a[k][l];
		}
	cout<<endl;
	for(int k=0;k<5;k++){
		for(int l=0;l<5;l++){
			if(a[k][l]==1)
				res=abs(2-k)+abs(2-l);
		}
	}
	cout<<res<<endl;
}
