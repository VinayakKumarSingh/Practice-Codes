#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool ePoint(int arr[],int n);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(ePoint(arr,n))
		cout<<"YES!! Equilibrium exist"<<endl;
	else
		cout<<"NO!!! Equilibrium doesn't exist"<<endl;
}
bool ePoint(int arr[],int n){
	int rs=0;
	for(int i=0;i<n;i++){
		rs+=arr[i];
	}
	int ls=0;
	for(int i=0;i<n;i++){
		rs-=arr[i];
		if(ls==rs)
			return true;
		ls+=arr[i];
	}
	return false;
}
