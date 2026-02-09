#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int j=0;
		int leaves=0;
		for(int i=1;i<=n;i++){
			leaves+=pow(i,i);
			j++;
			if(j>k)
				leaves-=pow(j-k,j-k);
		}
		if(leaves%2==0){
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}
