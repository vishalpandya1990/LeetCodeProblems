class Solution {
    public:
    int first, second;
    vector<vector<int>> res;
    void twoSum(vector<int>& nums, int start, int end, int target) {
        int n = end-start+1;
        if(n < 2) return;
        int left = start, right = end;
        while(left < right) {
            int curSum = nums[left] + nums[right];
            if(curSum == target) {
                vector<int> newResult;
                newResult.push_back(first);
                newResult.push_back(second);
                newResult.push_back(nums[left]);
                newResult.push_back(nums[right]);
                res.push_back(newResult);
                right--;
                while(left < right && nums[right] == nums[right+1])
                    right--;
            } else if(curSum < target) {
                left++;
            } else if(curSum > target) {
                right--;
            }

        }
    }   
    void threeSum(vector<int>& nums, int start, int end, int target) {
        int n = end-start+1;
        if(n < 3) return;
        for(int i = start; i <= end; i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            second = nums[i];
            twoSum(nums, i+1, end, target-second);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++) {
            if(i && nums[i] == nums[i-1]) continue;
            first = nums[i];
            threeSum(nums, i+1, n-1, target-first);
        }
        return res;
    }
};
