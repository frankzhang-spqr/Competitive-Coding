#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(const string& s, const string& goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};
