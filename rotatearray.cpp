#include<iostream>
using namespace std;
void rotatearray(int arr[],int n,int k);
void rotate(int arr[],int low,int high);
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int k;
	cin>>k;
	if(k>n)
		k=k%n;
	rotatearray(arr,n,k);
	
	cout<<"Rotated Array "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void rotatearray(int arr[],int n,int k){
	rotate(arr,0,k-1);
	rotate(arr,k,n-1);
	rotate(arr,0,n-1);
}
void rotate(int arr[],int low,int high){
	int temp=0;
	while(low<high){
		temp=arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
		low++;
		high--;
	}
}
