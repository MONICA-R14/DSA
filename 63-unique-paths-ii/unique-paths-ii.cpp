class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
          return solve(0,0,n,m,dp,obstacleGrid);
    }
    int solve(int i,int j,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
    {
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(obstacleGrid[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i,j+1,n,m,dp,obstacleGrid);
        int down=solve(i+1,j,n,m,dp,obstacleGrid);

        return dp[i][j]=right+down;
    }
};