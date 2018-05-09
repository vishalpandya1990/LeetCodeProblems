class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int i;
        for(i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1])
                break;
        }
        if(i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int j;
        for(j = n-1; j > i; j--) {
            if(nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};
