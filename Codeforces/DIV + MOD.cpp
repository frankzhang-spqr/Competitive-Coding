#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r, a;
        cin >> l >> r >> a;

        // Option 1: Directly calculate f_a(r)
        long long maxValue = (r / a) + (r % a);

        // Option 2: Calculate f_a(x) for x = r - (r % a) - 1, if within range
        long long x = r - (r % a) - 1;
        if (x >= l) {
            maxValue = max(maxValue, (x / a) + (x % a));
        }

        cout << maxValue << endl;
    }

    return 0;
}