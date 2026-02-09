#include<bits/stdc++.h>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int l,int r,int m);
void mergesort(vector<int> &arr,int l,int r){
	int m=l+(r-l)/2;
	if(l<r){
	mergesort(arr,l,m);
	mergesort(arr,m+1,r);
	merge(arr,l,r,m);
	}
	else
	return;
}
void merge(vector<int> &arr,int l,int r,int m){
	int n1=m-l+1;
	int n2=r-m;
	
	vector<int> left(n1);
	vector<int> right(n2);
	for(int i=0;i<n1;i++)	left[i]=arr[i+l];
	for(int i=0;i<n2;i++)	right[i]=arr[i+m+1];
	
	int i=0;int j=0;int k=l;
	while(i<n1&&j<n2){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
			k++;
		}
		else{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1)	{arr[k]=left[i]; i++; k++;}
	while(j<n2)	{arr[k]=right[j]; j++; k++;}
}
int main(){
	vector<int>arr;
	cout<<"Enter the values to be sorted"<<endl;
	cout<<"Press Enter key to input"<<endl;
	while(true){
		int i;
		cin>>i;
		arr.push_back(i);
		if(cin.peek()=='\n')
			break;
	}
	mergesort(arr,0,arr.size()-1);
	cout<<"Sorted array is : ";
	for(int i:arr){
		cout<<i<<" ";
	}
	cout<<endl;
}
