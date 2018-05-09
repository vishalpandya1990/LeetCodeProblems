class Solution {
public:
    int findMin(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        if(l > r) return nums[0];
        int m = (l + r)/2;
        if(m < r && nums[m+1] < nums[m]) return nums[m+1];
        if(m > l && nums[m-1] > nums[m]) return nums[m];
        if(nums[m] < nums[r]) return findMin(nums, l, m-1);
        return findMin(nums, m+1, r);
    }
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
};
