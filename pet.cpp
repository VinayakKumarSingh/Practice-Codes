#include <iostream>
#include <cctype> // For tolower
#include<cstring>
using namespace std;

int main() {
    char s1[102], s2[102];
    cin >> s1 >> s2;

    int sum1 = 0, sum2 = 0;
    
    for (int i = 0; i < strlen(s1); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        //sum1 += s1[i];
        //sum2 += s2[i];
    }
	int res=strcmp(s1,s2);
    if (res==0)
        cout << 0 << endl;
    else if (res<0)
        cout << -1 << endl;
    else
        cout << 1 << endl;

    // cout << s1 << endl;
    // cout << s2 << endl;

    return 0;
}

