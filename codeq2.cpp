#include <bits/stdc++.h>
using namespace std;

int compute_wait(int k, int t) {
    int remainder = k % t;
    return (t - remainder) % t;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, x, y, z;
        cin >> k >> x >> y >> z;
        int wait_x = compute_wait(k, x);
        int wait_y = compute_wait(k, y);
        int wait_z = compute_wait(k, z);
        cout << min({wait_x, wait_y, wait_z}) << "\n";
    }
    return 0;
}

