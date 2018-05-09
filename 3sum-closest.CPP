class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX, curDiff, curSum, minSum;
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = n-1;
            while(j < k) {
                int curSum = nums[i] + nums[j] + nums[k];
                int curDiff = curSum  - target;
                if(abs(curDiff) < minDiff) {
                    minDiff = abs(curDiff);
                    minSum = curSum;
                }
                if(curSum > target) {
                    k--;
                } else if(curSum < target) {
                    j++;
                } else {
                    return curSum;
                }
            }
        }
        return minSum;
    }
    int threeSumClosest1(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = INT_MIN, right = INT_MAX; 
        for(int i = 0; i < n-2; i++) {
            for(int j = i+1; j < n-1; j++) {
                for(int k = j+1; k < n; k++) {
                    int curSum = nums[i] + nums[j] + nums[k];
                    if(curSum == target)
                        return curSum; 
                    else if(curSum < target) {
                        left = max(left, curSum);
                    } else {
                        right = min(right, curSum);
                    }
                }
            }
        }
        if(left == INT_MIN) 
            return right;
        if(right == INT_MAX)
            return left;
        return (right - target) < (target - left) ? right : left;
    }
};
