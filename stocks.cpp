#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxprofit(int prices[],int n);
int main(){
	int n;
	cin>>n;
	int prices[n];
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	cout<<"Maximum Profit is "<<maxprofit(prices,n)<<endl;
}
int maxprofit(int prices[],int n){
	int profit=0;
	for(int i=1;i<n;i++){
		if(prices[i-1]<prices[i]){
			profit+=(prices[i]-prices[i-1]);
		}
	}
	return profit;
}
