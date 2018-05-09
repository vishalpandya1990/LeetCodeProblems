class Solution {
public:
    void merge(vector<int>& nums, int p, int q, int rr) {
        int n1 = q - p + 1;
        int n2 = rr - q;
        int left[n1], right[n2];
        int l = p, r = q+1, k;
        for(int i = 0; i < n1; i++)
            left[i] = nums[l++];
        for(int i = 0; i < n2; i++)
            right[i] = nums[r++];
        l = 0, r = 0, k = p;
        while(l < n1 && r < n2) {
            if(left[l] <= right[r]) {
                nums[k++] = left[l++];
            } else {
                nums[k++] = right[r++];
            }
        }
        while(l < n1) {
            nums[k++] = left[l++];
        }
        while(r < n2) {
            nums[k++] = right[r++];
        }
    }
    int reversePairs(vector<int>& nums, int l, int r) {
        if(l < r) {
            int q = (l + r) / 2;
            int count = 0;
            count += reversePairs(nums, l, q);
            count += reversePairs(nums, q+1, r);
            int leftIdx, rightIdx = q+1;
            for(leftIdx = l; leftIdx <= q; leftIdx++) {
                for(; rightIdx <= r && (nums[leftIdx]*1LL > 2LL*nums[rightIdx]); rightIdx++) {
  
                }
                count += rightIdx - q - 1;
            }
            merge(nums, l, q, r);
            return count;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        return reversePairs(nums, 0, nums.size()-1);
    }
};
