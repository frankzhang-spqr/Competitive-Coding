#include <string>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int even_sum = 0;
        int odd_sum = 0;
        
        for (int i = 0; i < num.length(); ++i) {
            int digit = num[i] - '0';
            if (i % 2 == 0) {
                even_sum += digit;
            } else {
                odd_sum += digit;
            }
        }
        
        return even_sum == odd_sum;
    }
};
