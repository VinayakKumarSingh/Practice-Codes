#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int coin=0;int res=0;
		int i;
		for(i=0;i<n;i++){
			if(a[i]!=0){
				coin=a[i];
				break;
			}
		}
		for(int j=i;j<n;j++){
			if(a[j]==0&&coin!=0)
				res++;
				coin--;
		}
		cout<<res<<endl;
	}
}
