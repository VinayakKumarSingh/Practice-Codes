#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int isMajority(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"The majority element is "<<isMajority(arr,n)<<endl;
}
int isMajority(int arr[],int n){
	int res=0;
	int count=1;
	for(int i=1;i<n;i++){
		if(arr[res]==arr[i])
			count++;
		else
			count--;
		if(count==0){
			res=i;
			count=1;
		}
	}
	count=0;
	for(int i=0;i<n;i++){
		if(arr[res]==arr[i]){
			count++;
		}
	}
	if(count>n/2)
		return arr[res];
	else
		return -1;
}
