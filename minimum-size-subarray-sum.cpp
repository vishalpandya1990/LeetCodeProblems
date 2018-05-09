class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] == s ? 1: 0;
        int start, end, minLen = n+1;
        long long curSum;
        start = end = 0;
        curSum = nums[0];
        while(start < n && end < n && start <= end) {
            if(curSum >= s) {
                minLen = min(minLen, end-start+1);
                curSum -= nums[start];
                start++;
            } else if(curSum < s) {
                end++;
                if(end < n)
                    curSum += nums[end];
            }
        }
        return minLen == n+1 ? 0 : minLen;
    }
};
