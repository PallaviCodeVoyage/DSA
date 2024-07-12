//this code uses the nested loops resulting in time complexity of O(n^2) and can be solved using dp and Manacher's algorithm(O(n))
class Solution {
public:
    string longestPalindrome(string s) {
        int maxl = INT_MIN;
        int sp = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxl) {
                        maxl = (j - i + 1);
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxl);
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
