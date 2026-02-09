#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxalternate(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"The maximum odd even alternating subarray is "<<maxalternate(arr,n)<<endl;
}
int maxalternate(int arr[],int n){
	int res=1;
	int curr=1;
	for(int i=1;i<n;i++){
		if((arr[i]%2==0&&arr[i-1]%2!=0)||
		(arr[i]%2!=0&&arr[i-1]%2==0)){
			curr++;
			res=max(res,curr);
		}
		
		else
			curr=1;
	}
	return res;
}
