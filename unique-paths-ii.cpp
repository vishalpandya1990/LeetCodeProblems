class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowSize = obstacleGrid.size();
        if(rowSize == 0) return 0;
        int colSize = obstacleGrid[0].size();
        long dp[rowSize][colSize];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for(int j = 1; j < colSize; j++) {
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }
        for(int i = 1; i < rowSize; i++) {
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }
        for(int i = 1; i < rowSize; i++) {
            for(int j = 1; j < colSize; j++) {
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rowSize-1][colSize-1];
    }
};
