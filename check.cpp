#include<iostream>
#include<string>
using namespace std;
bool checkpalin(string &str,int start,int end){
	if(start>=end)
		return true;
	return (str[start]==str[end])&&checkpalin(str,start+1,end-1);
}
int main(){
	string str;
	getline(cin,str);
	int start,end;
	start=0;
	end=str.length()-1;
	if(checkpalin(str,start,end)){
		cout<<"Palindrome"<<endl;
	}
	else
		cout<<"Not Palindrome"<<endl;
}

