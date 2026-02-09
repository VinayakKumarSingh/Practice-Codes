#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	char s[101];
	cin>>s;
	vector <int> a;
	for(int i=0;i<strlen(s);i++){
		if(i%2==0)
			a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		if(i==a.size()-1)
			cout<< a[i];
		else
			cout<< a[i]<<"+";
		}
	cout<<endl;
	return 0;
}
