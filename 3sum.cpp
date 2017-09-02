

/*
 * Problem statement :- https://leetcode.com/problems/3sum/description/
 */ 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++) {
            if(i && nums[i] == nums[i-1])
                continue;
            int target2sum = -nums[i];
            int start = i+1, end = n-1;
            while(start < end) {
                if(nums[start] + nums[end] == target2sum){
                    vector<int> v = {nums[i], nums[start], nums[end]};
                    res.push_back(v);
                    start++, end--;
                    while(start <= n-1 && nums[start] == nums[start-1])
                        start++;
                    while(end >= 0 && nums[end] == nums[end+1])
                        end--;
                } else if (nums[start] + nums[end] < target2sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }
       return res;   
    }
};
