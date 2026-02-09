#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void flip(bool arr[],int n);
int main(){
	int n;
	cin>>n;
	bool arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	flip(arr,n);
}
void flip(bool arr[],int n){
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1]){
			if(arr[i]!=arr[0])
				cout<<"Flip from "<<i<<" to ";
			else
				cout<<i-1<<endl;
		}
	}
	if(arr[0]!=arr[n-1])
			cout<<n-1<<endl;
}
