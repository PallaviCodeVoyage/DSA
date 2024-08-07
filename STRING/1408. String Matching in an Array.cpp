/****agar mujhe ye find krna h that whether the given string is the substring or present in the main string i can use find */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
    vector<string>result;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the comparison if the same string or if the length of words[i] > words[j]
                if (i != j && words[i].length() <= words[j].length()) {
                    if (words[j].find(words[i]) != string::npos) {
                        result.push_back(words[i]);
                        break; // No need to check further, as we've found a match
                    }
                }
            }
        }
        
        return result;
    }
};
