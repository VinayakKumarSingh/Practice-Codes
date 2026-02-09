#include<iostream>
using namespace std;
int insert(int arr[],int n,int cap,int pos, int item);
int main(){
	int arr[10],item,pos;
	cout<<"Enter the 5 values in the array"<<endl;
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	cout<<"Enter the item and the positon to be inserted"<<endl;
	cin>>item>>pos;
	
	int cap=10;
	int n=5;
	insert(arr,n,cap,pos,item);
	
}
int insert(int arr[],int n,int cap,int pos, int item){
	int idx=pos-1;
	if(pos==cap)
		return n;
	else{
		for(int i=n-1;i>=idx;i--){
			arr[i+1]=arr[i];
		}
	}
	arr[idx]=item;
	n=n+1;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return n;	
}
