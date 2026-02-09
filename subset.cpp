#include<iostream>
#include<string>
using namespace std;
void subsets(string,string,int);
int main(){
	string s;
	getline(cin,s);
	string curr;
	int index;
	subsets(s,curr,index);
}
void subsets(string s,string curr="",int index=0){
	if(index==s.length()){
		cout<<curr<<" ";
		return;
	}
	subsets(s,curr,index+1);
	subsets(s,curr+s[index],index+1);
}
