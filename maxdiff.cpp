#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxDiff(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<maxDiff(a,n)<<endl;
}
int maxDiff(int a[],int n){
	int minval=a[0];
	int res=a[1]-a[0];
	for(int i=1;i<n;i++){
		res=max(res,a[i]-minval);
		minval=min(minval,a[i]);
	}
	return res;
}
