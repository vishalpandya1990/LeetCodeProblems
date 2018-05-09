class Solution {
public:
    void winner(vector<int>&nums, vector<vector<int>>& dp) {
        int n = nums.size();
        for(int row = n-1; row >= 0; row--)  {
            for(int col = row; col < n; col++) {
                if(row == col) dp[row][col] = nums[row];
                else if(row == col-1) dp[row][col] = max(nums[row], nums[col]);
                else {
                    int a = nums[row] - dp[row+1][col];
                    int b = nums[col] - dp[row][col-1];
                    dp[row][col] = max(a, b);
                }
            }
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        winner(nums, dp);
        return dp[0][n-1] >= 0;
    }
};
