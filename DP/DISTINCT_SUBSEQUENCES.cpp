/*class Solution {
public:
int countSubsequences(string &s, string &t, int i, int j) {
    // Base case 1: If we've matched all characters of t
    if (j == t.size()) {
        return 1; // We've found a valid subsequence
    }

    // Base case 2: If we've exhausted all characters of s without matching t
    if (i == s.size()) {
        return 0; // No valid subsequence can be formed
    }

    // Recursive case 1: Characters at s[i] and t[j] match
    if (s[i] == t[j]) {
        // Two choices:
        // 1. Include s[i] in the subsequence
        int include = countSubsequences(s, t, i + 1, j + 1);
        
        // 2. Exclude s[i] and continue
        int exclude = countSubsequences(s, t, i + 1, j);
        
        // Return the sum of both choices
        return include + exclude;
    } 
    // Recursive case 2: Characters at s[i] and t[j] do not match
    else {
        // Skip s[i] and continue with the next character in s
        return countSubsequences(s, t, i + 1, j);
    }
}

    int numDistinct(string s, string t) {
        
        return countSubsequences(s,t,0,0);
    }
};*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
        return countSubsequences(s, t, 0, 0, memo);
    }

private:
    int countSubsequences(string &s, string &t, int i, int j, vector<vector<int>> &memo) {
        if (j == t.size()) return 1; // If we've matched all of t, return 1 as a valid subsequence is found
        if (i == s.size()) return 0; // If we've exhausted s without matching all of t, return 0
        
        if (memo[i][j] != -1) return memo[i][j]; // If already computed, return the stored result

        if (s[i] == t[j]) {
            memo[i][j] = countSubsequences(s, t, i + 1, j + 1, memo) + countSubsequences(s, t, i + 1, j, memo);
        } else {
            memo[i][j] = countSubsequences(s, t, i + 1, j, memo);
        }

        return memo[i][j];
    }
};
