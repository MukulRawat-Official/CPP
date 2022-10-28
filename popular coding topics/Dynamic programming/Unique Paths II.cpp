/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid)
    {
        if(grid[i][j]==1) return 0;
        
        if(i==0 and j==0) return 1;
        if(i==0) return dp[i][j-1];
        if(j==0) return dp[i-1][j]; 
            
        return dp[i-1][j] + dp[i][j-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1]==1) return 0;
        
        vector<vector<int>> dp(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        dp[i][j] = solve(i,j,dp, obstacleGrid);
        
        return dp[n-1][m-1];
    }
};
