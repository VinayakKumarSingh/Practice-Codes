#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        
        // Find the maximum and second maximum values
        int max1 = *max_element(array.begin(), array.end());
        int max2 = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (array[i] != max1) {
                max2 = max(max2, array[i]);
            }
        }
        
        cout << max2 << '\n';
    }
    
    return 0;
}

