class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if(n == 0) return res;
        if(n == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int rangeStart = nums[0], rangeEnd;
        int cur = 1;
        while(cur < n) {
            if(nums[cur] != nums[cur-1] + 1) {
                rangeEnd = nums[cur-1];
                if(rangeEnd == rangeStart) // no duplicates
                    res.push_back(to_string(rangeStart));
                else {
                    res.push_back(to_string(rangeStart) + "->" + to_string(rangeEnd));
                }
                rangeStart = nums[cur];
            }
            cur++;
        }
        if(rangeStart == nums[n-1]) // no duplicates
            res.push_back(to_string(rangeStart));
        else
            res.push_back(to_string(rangeStart) + "->" + to_string(nums[n-1]));
        return res;
    }
};
