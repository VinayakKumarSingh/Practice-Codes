#include<iostream>
using namespace std;
void movezero(int a[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	movezero(arr,n);
	for(int i=0;i<n;i++){
		if(i<n-1)
			cout<<arr[i]<<", ";
		else
			cout<<arr[i]<<endl;
	}
}
void movezero(int a[],int n){
	int count=0;
	int t=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			t=a[i];
			a[i]=a[count];
			a[count]=t;
			count++;
		}
	}
}
