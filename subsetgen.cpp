#include<iostream>
#include<vector>
using namespace std;
void subset(vector <int>a,vector <int> curr,int index);
int main(){
	vector <int> a;
	cout<<"Enter the number of set elements present"<<endl;
	int num;
	cin>>num;
	for(int i=0;i<num;i++){
		a.push_back(i*num);
	}
	vector <int> curr;
	int index;
	subset(a,curr,index);
	for(int i=0;i<curr.size();i++)
		cout<<curr[i]<<" ";
		cout<<endl;
}
void subset(vector <int>a,vector <int> curr,int index=0){
	if(index==a.size()){
		curr.push_back(a[index]);
		return;
	}
		subset(a,curr,index+1);
		curr.push_back(a[index]);	
		subset(a,curr,index+1);
}
