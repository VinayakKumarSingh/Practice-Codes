#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void freq(int a[],int n);
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	freq(a,n);
}
void freq(int a[],int n){
	int frequency=1;
	int i=1;
	while(i<n){
		while(i<n&&a[i]==a[i-1]){
			frequency++;
			i++;
		}
		cout<<a[i-1]<<" "<<frequency<<endl;
		i++;
		frequency=1;
	}
	if(n==1||a[n-1]!=a[n-2])
		cout<<a[n-1]<<" "<<frequency<<endl;
}
