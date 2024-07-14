/******Gives TLE  brute force approach************/
/*class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        string rev=s;
       reverse(rev.begin(),rev.end());
        for(int i=0;i<=n;i++)
        {
            if(s.substr(0,n-i)==rev.substr(i))
            {
                return rev.substr(0,i)+s;
            }
        }
        return "";
        
    }
};*/
/*****************KMP BASED SOLUTION****O(N)************/
class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        // Edge case: If s is empty, return empty string
        if (s.empty()) return "";

        // Reverse the string to get rev_s
        std::string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());

        // Create the combined string and this symbol is added in order to differentiate between the given string and the reversed one
        std::string combined = s + "#" + rev_s;

        // Compute the LPS array for the combined string
        std::vector<int> lps = computeLPSArray(combined);

        // Find the length of the longest palindromic prefix in s
        int longest_palindromic_prefix_len = lps.back();

        // Get the characters to add at the beginning of s
        std::string to_add = s.substr(longest_palindromic_prefix_len);// we finding out the characters which needs to be added or are not the part of prefix/suffix substring
        std::reverse(to_add.begin(), to_add.end());

        // Form the shortest palindrome by adding to_add in front of s
        return to_add + s;
    }

private:
    //  LPS array
    std::vector<int> computeLPSArray(const std::string& str) {
        int n = str.size();
        std::vector<int> lps(n, 0);
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};
