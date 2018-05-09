class Solution {
public:
    vector<vector<int>> res;
    void subsets(vector<int>& nums, int curIndexToChoose, vector<int>& output) {
        int n = nums.size();
        if(n == curIndexToChoose) {
            vector<int> copy(output);
            sort(copy.begin(), copy.end());
            if(find(res.begin(), res.end(), copy) == res.end()) {
                res.push_back(copy);
            }
            return;
        }
        output.push_back(nums[curIndexToChoose]);
        subsets(nums, curIndexToChoose+1, output);
        output.pop_back();
        subsets(nums, curIndexToChoose+1, output);
    }
    vector<vector<int>> subsetsWithDup (vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return res;
        if(n == 1) {
            res.push_back(nums);
            res.push_back(vector<int>());
            return res;
        }
        vector<int> output;
        subsets(nums, 0, output);
        return res;
    }
};
