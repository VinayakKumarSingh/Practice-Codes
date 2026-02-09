#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void convert(string exp);
char assoc(char c);
int prec(char c);
int main(){
	string exp;
	cout<<"Enter the expression "<<endl;
	getline(cin,exp);
	convert(exp);
}
int prec(char c){
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}
char assoc(char c){
	if(c=='^')
		return 'R';
	else
		return 'L';
}
void convert(string exp){
	stack<char>s;
	string result;
	for(char c:exp){
		//if the scanned character is operand we directly add it in the result expression
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
			result+=c;
		//if the scanned character is ( we push into the stack
		else if(c=='(')
			s.push(c);
		//if we come across a ) we add all the expression into the result and at the end we pop (
		else if(c==')'){
			while(!s.empty() && s.top()!='('){
				result+=s.top();
				s.pop();
			}
			if(!s.empty())
				s.pop();//pops (
		}
		//if the scanned operator is not any of these then it is an operator and we add into the stack if it has a higher precedence or if it is empty else we add it directly into the output expression
		else{
			while(!s.empty() && prec(c)<prec(s.top())||
				!s.empty() && prec(c)==prec(s.top())&&
				assoc(c)=='L'){
					result+=s.top();
					s.pop();
				}
				s.push(c);
		}
		//Add the remaining elements to the result expression
		
	}
		while(!s.empty()){
			result+=s.top();
			s.pop();
		}
		cout<<result<<endl;
}
