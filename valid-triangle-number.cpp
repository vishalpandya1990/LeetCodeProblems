class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < n-2; i++) {
            for(int j = i+1, k = i+2; j < n-1  && nums[i] != 0; j++) {    //nums[j] <= nums[k], already
                while(k < n && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
};
