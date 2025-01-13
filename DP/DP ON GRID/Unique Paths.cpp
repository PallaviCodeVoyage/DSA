//MEMOISATION
class Solution {
public:
int solve(int i,int j,int rows,int col, vector<vector<int>>&dp)
{
    if(i<0||i>=rows||j<0||j>=col)
    {
        return 0;
    }
    if(i==rows-1&&j==col-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int r=solve(i,j+1,rows,col,dp);
    int d=solve(i+1,j,rows,col,dp);
    return dp[i][j]= r+d;

}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);

        
    }
};

//BOTTOM UP
class Solution {
public:

    int uniquePaths(int m, int n) {
        //step 1 making a vector or dp table as per the number of vectors being changed
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //setp 2 defining the state definition
        //dp[i][j] it states the total number of ways that we have saved in dp to rech at i row and j column
        //step3 to fill base cases
        dp[0][0]=0;
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
             dp[i][0]=1;
             dp[0][j]=1;
        }
       }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
        
    }
};
