*****BRUTE FORCE****O(N^3)***********
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        int maxLength = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (allUnique(s, i, j)) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        
        return maxLength;
    }
    
private:
    bool allUnique(string s, int start, int end) {
        unordered_set<char> seen;
        for (int i = start; i <= end; ++i) {
            if (seen.count(s[i])) {
                return false;
            }
            seen.insert(s[i]);
        }
        return true;
    }
};
******************SLIDING WINDOW USING HASH MAP ***O(N)**********************
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            if (lastIndex.find(s[right]) != lastIndex.end() && lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
****************using SET****************
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        unordered_set<char> seen;
        int maxLength = 0, left = 0, right = 0;
        
        while (right < n) {
            if (seen.count(s[right]) == 0) {
                seen.insert(s[right++]);
                maxLength = max(maxLength, (int)seen.size());
            } else {
                seen.erase(s[left++]);
            }
        }
        
        return maxLength;
    }
};

