class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {
            sort(nums.begin(), nums.end());
            return;
        }
        int z = 0, t = n-1, i;
        for(i = 0; i <= t; ) {
            //cout << "i = " << i << " ";
            if(nums[i] == 0) {
                //cout << "zero swap\n";
                swap(nums[i], nums[z]);
                z++; i++;
            } else if(nums[i] == 2) {
                //cout << "two swap\n";
                swap(nums[i], nums[t]);
                t--;
            } else {
                //cout << "no swap\n";
                i++;
            }
        }
    }
};

