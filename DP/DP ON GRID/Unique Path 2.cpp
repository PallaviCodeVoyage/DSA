// class Solution {
// public:
// int solve(int i,int j,int rows,int cols,vector<vector<int>>obstacleGrid,vector<vector<int>>&dp)
// {
//     if(i<0||i>=rows||j<0||j>=cols)
//     {
//         return 0;
//     }

//     if(obstacleGrid[i][j]==1)
//     {
//         return 0;
        
//     }
//     if(i==rows-1&&j==cols-1)
//     {
//         return 1;
//     }

//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }

//     int r=solve(i,j+1,rows,cols,obstacleGrid,dp);
//     int d=solve(i+1,j,rows,cols,obstacleGrid,dp);
//     return dp[i][j]=r+d;
// }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int rows=obstacleGrid.size();
//         int cols=obstacleGrid[0].size();
//         vector<vector<int>>dp(rows,vector<int>(cols,-1));
        
//         return solve(0,0,rows,cols,obstacleGrid,dp);
        
//     }
// };



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        // If start or end cell has an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1) {
            return 0;
        }

        // Initialize the dp table
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1; // Start cell

        // Initialize the first row
        for (int j = 1; j < cols; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            } else {
                break; // Obstacle encountered, no paths beyond this point in the row
            }
        }

        // Initialize the first column
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            } else {
                break; // Obstacle encountered, no paths beyond this point in the column
            }
        }

        // Fill the rest of the dp table
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};
