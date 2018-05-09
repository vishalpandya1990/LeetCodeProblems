class Solution {
public:
    int firstOccurence(vector<int>& nums, int lo, int hi, int target) {
        if(lo <= hi) {
            int mid = (lo + hi)/2;
            if( (nums[mid] == target) && ((mid == lo)||(nums[mid-1] < target)) ) return mid;
            else if(nums[mid] < target)
                return firstOccurence(nums, mid+1, hi, target);
            else
                return firstOccurence(nums, lo, mid-1, target);
        }
        return -1;
    }
    int lastOccurence(vector<int>& nums, int lo, int hi, int target) {
        if(lo <= hi) {
            int mid = (lo + hi)/2;
            if( (nums[mid] == target) && ((mid == hi)||(nums[mid+1] > target)) ) return mid;
            else if(nums[mid] <= target)
                return lastOccurence(nums, mid+1, hi, target);
            else
                return lastOccurence(nums, lo, mid-1, target); 
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        if(n == 0) { 
            return res;
        }
        if(n == 1) {
            if(nums[0] == target) {
                res[0] = res[1] = 0;
            }
            return res;
        }
        int f = firstOccurence(nums, 0, n-1, target);
        int l = lastOccurence(nums, 0, n-1, target);
        res[0] = f;
        res[1] = l;
        return res;
    }
};
