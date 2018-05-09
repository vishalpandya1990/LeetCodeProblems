	class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size();
        int nb = B.size();
        if(na == 0 || nb == 0) return 0;
        int dp[na][nb] = {0};
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        for(int col = 1; col < nb; col++) {
            dp[0][col] = 0;
            if(A[0] == B[col])
                dp[0][col] = 1;
        }
        for(int row = 1; row < na; row++) {
            dp[row][0] = 0;
            if(A[row] == B[0])
                dp[row][0] = 1;
        }
        int ans = 0;
        for(int row = 1; row < na; row++) {
            for(int col = 1; col < nb; col++) {
                if(A[row] == B[col])
                    dp[row][col] = 1 + dp[row-1][col-1];
                else
                    dp[row][col] = 0;
                ans = max(ans, dp[row][col]);
            }
        }
        return ans;
    }
};
