#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector <int> a;
	for(int i=0;i<a.size();i++)
		cin>>a[i];
	sort(begin(a),end(a));
	for(int i=0;i<10;i++){
		cout<<a[i]<<"\n";
	}
}
