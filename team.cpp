#include<iostream>
using namespace std;
int main(){
	int n;int res=0;
	cin>>n;
	while(n!=0){
		int arr[3];
		for(int i=0;i<3;i++)
			cin>>arr[i];
		if(arr[0]==1&&arr[1]==1)
			res++;
		else if(arr[1]==1&&arr[2]==1)
			res++;
		else if(arr[0]==1&&arr[2]==1)
			res++;
		n--;
	}
	cout<<res<<endl;
}
