class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& v) {
        if (i >= a.size() || j >= b.size()) {
            return 0;
        }
        if (v[i][j] != -1) {
            return v[i][j];
        }
        if (a[i] == b[j]) {
            v[i][j] = 1 + solve(a, b, i + 1, j + 1, v);
        } else {
            v[i][j] = max(solve(a, b, i + 1, j, v), solve(a, b, i, j + 1, v));
        }
        return v[i][j];
    }

    string findLCS(string &a, string &b, vector<vector<int>>& v) {
        int i = 0, j = 0;
        string lcs = "";
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                lcs += a[i];  // If characters match, it's part of the LCS
                i++;
                j++;
            } else if (v[i + 1][j] >= v[i][j + 1]) {//hint given
                i++;  // Move to the next character in a
            } else {
                j++;  // Move to the next character in b
            }
        }
        return lcs;
    }

    string longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.length();
        int s2 = text2.length();
        vector<vector<int>> v(s1, vector<int>(s2, -1));
        solve(text1, text2, 0, 0, v);  // Fill the memoization table
        return findLCS(text1, text2, v);  // Backtrack to find the LCS string
    }
};

HINT: TO HELP ME OUT IF I DONT RECALL THE SIGNIFICANCE OF THE STEP
  /*
Option 1: If you move forward on the first map, you’ll see how many treasures you can collect if you take that path (v[i + 1][j]).
Option 2: If you move forward on the second map, you’ll check how many treasures you’d get on that path (v[i][j + 1]).
If moving forward on the first map (i + 1) shows you as many or more treasures than moving on the second map, you choose to move forward on the first map. Otherwise, you move forward on the second map.*/
