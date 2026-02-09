#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxNormal(int arr[],int n);
int maxCircular(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"The maximum sum of circular subarray is "<<maxCircular(arr,n)<<endl;
}
int maxNormal(int arr[],int n){
	int res=arr[0];
	int maxsofar=arr[0];
	for(int i=1;i<n;i++){
		maxsofar=max(arr[i],maxsofar+arr[i]);
		res=max(maxsofar,res);
	}
	return res;
}
int maxCircular(int arr[],int n){
	int normal_sum=maxNormal(arr,n);
	if(normal_sum<0){
		return normal_sum;
	}
	int arr_sum=0;
	for(int i=0;i<n;i++){
		arr_sum+=arr[i];
		arr[i]=-arr[i];
	}
	int circular_sum=arr_sum+maxNormal(arr,n);
	return max(normal_sum,circular_sum);
}
