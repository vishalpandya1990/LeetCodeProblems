class Solution {
public:
    int findPeakElement(vector<int>& nums, int l, int r) {
        if(l == r) return l;
        if(l > r) return -1;
        int m = (l + r)/2;
        bool left = (m == l) || (nums[m] > nums[m-1]);
        bool right = (m == r) || (nums[m] > nums[m+1]);
        if(left && right) return m;
        else if(left) return findPeakElement(nums, m+1, r);
        else return findPeakElement(nums, l, m-1);
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return 0;
        return findPeakElement(nums, 0, n-1);
    }
};
