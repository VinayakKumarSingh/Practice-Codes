#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void leaders(int arr[],int n);
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	leaders(arr,n);
	cout<<endl;
}
void leaders(int arr[],int n){
	vector<int>curr;
	curr.push_back(arr[n-1]);
	int idx=0;
	for(int i=n-2;i>=0;i--){
		if(arr[i]>curr[idx]){
			curr.push_back(arr[i]);
			idx++;
		}
	}
	cout<<"Leaders of array "<<endl;
	reverse(curr.begin(),curr.end());
	for(int i=0;i<curr.size();i++)
		cout<<curr[i]<<" ";
}
