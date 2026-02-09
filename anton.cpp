#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    s.erase(remove(s.begin(), s.end(), '}'), s.end());
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    set<char> unique_chars;
    for(int i = 0; i < s.length(); i += 2) {
        unique_chars.insert(s[i]);
    }

    int res = unique_chars.size();
    cout << res << endl;
}

