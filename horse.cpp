#include <iostream>
#include <set>
using namespace std;

int main() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    set<int> horseshoes;
    horseshoes.insert(s1);
    horseshoes.insert(s2);
    horseshoes.insert(s3);
    horseshoes.insert(s4);

    cout << 4 - horseshoes.size() << endl;

    return 0;
}
