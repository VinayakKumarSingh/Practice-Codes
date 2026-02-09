#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxsum(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"The maximum subarray is "<<maxsum(arr,n)<<endl;
}
int maxsum(int arr[],int n){
	int res=arr[0];

	for(int i=0;i<n;i++){
		int curr=0;
		for(int j=i;j<n;j++){
			curr+=arr[j];
			res=max(res,curr);
		}
	}
	return res;
}
