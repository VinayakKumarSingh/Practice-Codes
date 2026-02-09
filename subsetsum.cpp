#include<iostream>
using namespace std;
int subsets(int arr[],int n,int sum);
int main(){
	int num;
	cout<<"Enter the Number of elements in an array"<<endl;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}
	int sum;
	cout<<"Enter the sum required"<<endl;
	cin>>sum;
	cout<<"The total number of subsets whose sum is "<<sum<<" is "<<subsets(arr,num,sum)<<endl;
}
int subsets(int arr[],int n,int sum){
	if(n==0){
		if(sum==0)
			return 1;
		else
			return 0;
	}
	return subsets(arr,n-1,sum)+subsets(arr,n-1,sum-arr[n-1]);
}
