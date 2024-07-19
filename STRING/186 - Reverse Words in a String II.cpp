/* main idea is we have used two pointer concept the situation says that we are given with a sorted array or vector of characters and we need to reverse the words*/
/*step 1: reverse the whole string and then reverse each word*/
/*Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]*/
#include <vector>
#include <algorithm> // for swap

class Solution {
public:
    void reverseWords(std::vector<char>& s) {
        int n = s.size();
        int i = 0;

        // Reverse each word in the string
        for (int j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s, i, j);
            }
        }

        // Reverse the entire string
        reverse(s, 0, n - 1);
    }

private:
    void reverse(std::vector<char>& s, int i, int j) {
        while (i < j) {
            std::swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};
