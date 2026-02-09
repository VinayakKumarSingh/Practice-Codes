#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxones(bool arr[],int n);
int main(){
	int n;
	cin>>n;
	bool arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"The maximum no.of consecutive ones are "<<maxones(arr,n)<<endl;
}
int maxones(bool arr[],int n){
	int res=0;
	int curr=0;
	for(int i=0;i<n;i++){
		if(arr[i]==0)
			curr=0;
		if(arr[i]==1){
			curr++;
			res=max(res,curr);
		}
	}
	return res;
}
