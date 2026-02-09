#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int t,n,m,q;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		int a[m];
		int Q;
		int min;
		for(int i=0;i<m;i++)
			cin>>a[i];
		cin>>Q;
		min=abs(a[0]-Q);
		for(int j=0;j<m;j++){
			if(abs(a[j]-Q)<min)
				min=abs(a[j]-b[0]);
		}
		cout<<min<<endl;
	}
}
