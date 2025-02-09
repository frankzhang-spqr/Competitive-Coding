#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort to maximize differences in min and max accumulations
        sort(a.begin(), a.end());
        
        int min_sum = 0, max_sum = 0;
        int min_val = a[0], max_val = a[n - 1];
        
        for (int i = 1; i < n; i++) {
            min_sum += min_val;
            max_sum += max_val;
        }

        cout << max_sum - min_sum << endl;
    }
    return 0;
}