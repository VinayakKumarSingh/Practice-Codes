#include<iostream>
using namespace std;
int main(){
	int a[10]={12,13,7,8,9,0,4,9,4,1};
	int temp=0;
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			if(a[i]>a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
	for(int i=0;i<10;i++){
	cout<<a[i]<<endl;
	}
}
