#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int remainder = n % 2020;
        int quotient = n / 2020;
        
        // Check if the remainder can be made up with 2021's within the quotient constraint
        if (remainder <= quotient) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}