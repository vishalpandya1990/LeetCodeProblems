class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowSize = triangle.size();
        if(rowSize == 0) return 0;
        if(rowSize == 1) return triangle[0][0];
        vector<int> dp(triangle[rowSize-1]);
        for(int curRow = rowSize-2; curRow >= 0; curRow--) {
            for(int curElem = 0; curElem < triangle[curRow].size(); curElem++) {
                dp[curElem] = triangle[curRow][curElem] + min(dp[curElem], dp[curElem+1]);
            }
        }
        return dp[0];
    }
};
