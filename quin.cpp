#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag=true;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			int diff=abs(a[i]-a[i-1]);
			if(diff!=5&&diff!=7){
				flag=false;
				break;
			}
		}
		if(flag==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
