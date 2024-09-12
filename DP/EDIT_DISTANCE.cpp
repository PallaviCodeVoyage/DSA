/*class Solution {
public:

int solve(string a,string b,int i,int j,int m,int n)
{
   
    if(j>=n)
    {
        return m-i;//itne element hataenge so these many more operations

    }
    else if(i>=m)
    {
        return n-j;//itne elements aur add krne hain in string one
    }

    if(a[i]==b[j])
    {
        return solve(a,b,i+1,j+1,m,n);
    }
    int rep=1+solve(a,b,i+1,j+1,m,n);
    int insert=1+solve(a,b,i,j+1,m,n);//ye bhut imp hain understand tha we are imagining that  we have performed the step of insertion
    //also and no  actual ages are made so i ko change nhi krri and j ko kia so that can find next element in second string and see if it matches this one

    int del=1+solve(a,b,i+1,j,m,n);
    return min(rep,min(insert,del));
}
    int minDistance(string word1, string word2) {
       int m=word1.length();
       int n=word2.length();
        return solve(word1,word2,0,0,m,n);
    }
};*/

class Solution {
public:
    int solve(string &a, string &b, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (j >= n) {
            return m - i; // Delete remaining characters from a
        }
        if (i >= m) {
            return n - j; // Insert remaining characters from b
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return memoized result
        }

        if (a[i] == b[j]) {
            dp[i][j] = solve(a, b, i + 1, j + 1, m, n, dp); // Characters match, move both indices
        } else {
            int rep = 1 + solve(a, b, i + 1, j + 1, m, n, dp);  // Replace a[i] with b[j]
            int insert = 1 + solve(a, b, i, j + 1, m, n, dp);   // Insert b[j] into a
            int del = 1 + solve(a, b, i + 1, j, m, n, dp);      // Delete a[i]
            dp[i][j] = min(rep, min(insert, del));              // Store the minimum result
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Adjust size to (m+1) x (n+1)
        return solve(word1, word2, 0, 0, m, n, dp);
    }
};
