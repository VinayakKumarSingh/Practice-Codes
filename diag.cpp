#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // If there are no chips, no diagonals are occupied
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }

        // The minimum number of occupied diagonals can be calculated as follows:
        // Distribute the chips as evenly as possible on the diagonals.
        // There are 2n-1 diagonals on an n x n board.
        // Since each diagonal can hold at most n chips, we are only concerned with at most 2*n - 1 diagonals.

        // The chips are distributed among diagonals:
        // - if k <= n, they will all go on the first k diagonals (i.e., they can fit within k diagonals)
        // - if k > n, the distribution will start to require additional diagonals

        int minDiagonals;
        if (k <= n) {
            minDiagonals = 1;
        } else if (k <= 2 * n - 1) {
            minDiagonals = ceil(k/n);  // distribute k chips over diagonals with at most n per diagonal
        } else {
            minDiagonals = 2 * n - 1;  // all diagonals will be occupied if k > n*(2*n - 1)
        }

        cout << minDiagonals << endl;
    }
    return 0;
}

