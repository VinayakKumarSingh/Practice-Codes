#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t!=0){
		int a[4];
		int res=0;
		for(int i=0;i<4;i++)
			cin>>a[i];
		for(int j=1;j<4;j++){
			if(a[j]>a[0])
				res++;
		}
		cout<<res<<endl;
		t--;
	}
	return 0;
}
