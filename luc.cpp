#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num = n;
    bool isLucky = true;
	if(n%4==0||n%7==0||n%47==0){
		isLucky = true;
		goto output;
	}
    while(num > 0){
        int dig = num % 10;
        if(dig != 4 && dig != 7){
            isLucky = false;
            break;
        }
        num = num / 10;
    }
output:
    if(isLucky)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

