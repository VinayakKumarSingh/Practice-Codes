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
	cout<<"The maximum sum of circular subarray is "<<maxsum(arr,n)<<endl;
}
int maxsum(int arr[],int n){
	int res=0;
	for(int i=0;i<n;i++){
		int curr_sum=arr[i];
		int max_sum=arr[i];
		for(int j=1;j<n;j++){
			int index=(i+j)%n;
			curr_sum+=arr[index];
			max_sum=max(max_sum,curr_sum);
		}
		res=max(max_sum,res);
	}
	return res;
}
