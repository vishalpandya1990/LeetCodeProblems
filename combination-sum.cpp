class Solution {
public:
    vector<vector<int>> res;
    void getAllCombinations(vector<int>& nums, int nextIndex, int remTarget, vector<int>& comb) {
        if(remTarget == 0) {
            vector<int> sortedComb(comb);
            sort(sortedComb.begin(), sortedComb.end());
            if(find(res.begin(), res.end(), sortedComb) == res.end())
                res.push_back(sortedComb);
            return;
        }
        int n = nums.size();
        if(nextIndex == n) return;
        if(remTarget < 0) return;
        if(nums[nextIndex] <= remTarget) {
            comb.push_back(nums[nextIndex]);
            getAllCombinations(nums, nextIndex, remTarget - nums[nextIndex], comb);
            comb.pop_back();
        }
        getAllCombinations(nums, nextIndex+1, remTarget, comb);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        res = vector<vector<int>>();
        if(n == 0) {
            return res;
        }
        vector<int> tmp;
        getAllCombinations(candidates, 0, target, tmp);
        return res;
    }
};
