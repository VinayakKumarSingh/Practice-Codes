#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << -1 << "\n";
        return;
    }
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            int complement = n / d;
            if (d != complement) {
                cout << 1 << " " << d << " " << complement << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

