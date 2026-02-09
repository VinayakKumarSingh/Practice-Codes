#include<iostream>
using namespace std;
int secondLargest(int arr[],int n);
int main(){
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<arr[secondLargest(arr,n)]<<endl;
}
int secondLargest(int arr[],int n){
	int largest=0;
	int res=-1;
	for(int i=1;i<n;i++){
		if(arr[i]>arr[largest]){
			res=largest;
			largest=i;
		}
		else if(arr[i]!=arr[largest]){
			if(res==-1||arr[i]>arr[res])
				res=i;
		}
	}
	return res;
}
