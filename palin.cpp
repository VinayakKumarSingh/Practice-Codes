#include<iostream>
#include<string>
using namespace std;
bool isPalin(string &str,int start, int end);
int main(){
	string str;
	cout<<"Enter a string "<<endl;
	getline(cin,str);
	int n=str.length();
	int start=0;
	int end=n-1;
	if(isPalin(str,start,end))
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not a palindrome"<<endl;
}
bool isPalin(string &str,int start, int end){
	if(start>=end)
		return true;
	return(str[start]==str[end])&&isPalin(str,start+1,end-1);
}
