#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        
        // Split the sentence into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Check if each word's last character matches the next word's first character
        int n = words.size();
        for (int i = 0; i < n; i++) {
            char lastChar = words[i].back();
            char nextFirstChar = words[(i + 1) % n][0];
            if (lastChar != nextFirstChar) {
                return false;
            }
        }
        
        return true;
    }
};
