#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        int m = s.size();
        int n = p.size();
        
        // DP table with dimensions (m+1) x (n+1)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty pattern matches empty string
        dp[0][0] = true;
        
        // Initialize DP for patterns that start with '*' (they can match an empty string)
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // '*' can match empty (dp[i][j-1]) or any sequence (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    // '?' matches any single character, or exact match for characters
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        // The result is whether the entire string matches the entire pattern
        return dp[m][n];
    }
};
