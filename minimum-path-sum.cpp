class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int rowSize = grid.size();
        if(rowSize == 0) return 0;
        if(rowSize == 1) {
            int sum = 0;
            for(int n : grid[0])
                sum += n;
            return sum;
        }
        int colSize = grid[0].size();
        int dp[rowSize][colSize] = {0};
        dp[0][0] = grid[0][0];
        for(int i = 1; i < rowSize; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < colSize; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < rowSize; i++) {
            for(int j = 1; j < colSize; j++) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[rowSize-1][colSize-1];
    }
};
