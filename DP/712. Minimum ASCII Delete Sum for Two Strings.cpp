class Solution {
public:
    int solve(string &s1, string &s2, int i, int j,vector<vector<int>>& dp,int l,int m) {
        // Base Case 1: If we have exhausted s1, sum the remaining characters in s2
        if (i == l) {
            int sum = 0;
            for (int k = j; k < m; k++) {
                sum += s2[k];
            }
            return sum;
        }
        
        // Base Case 2: If we have exhausted s2, sum the remaining characters in s1
        if (j == m) {
            int sum = 0;
            for (int k = i; k < l; k++) {
                sum += s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        // If the current characters are equal, move to the next characters in both strings
        if (s1[i] == s2[j]) {
            return dp[i][j]=solve(s1, s2, i + 1, j + 1,dp,l,m);
        } else {
            // Otherwise, we have two options:
            // 1. Delete the current character from s1
            int deleteFromS1 = s1[i] + solve(s1, s2, i + 1,j,dp,l,m);
            // 2. Delete the current character from s2
            int deleteFromS2 = s2[j] + solve(s1, s2, i, j + 1,dp,l,m);
            
            // Return the minimum cost between the two options
            return dp[i][j]=min(deleteFromS1, deleteFromS2);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int l=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(l,vector<int>(m,-1));
        return solve(s1, s2, 0, 0,dp,l,m);
    }
};
