#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a >= b) {
            cout << a << "\n";  // She can deposit all her coins
        } else {
            // Calculate how much she needs to put into the unprofitable deposit
            long long x = b - a;  // x is how much she must deposit into Unprofitable

            // Calculate maximum deposit into Profitable
            long long maxDeposit = a - x;

            if (maxDeposit < 0) {
                cout << "0\n";  // Not enough coins to open the Profitable account
            } else {
                cout << maxDeposit << "\n";  // Maximum she can deposit into Profitable account
            }
        }
    }

    return 0;
}