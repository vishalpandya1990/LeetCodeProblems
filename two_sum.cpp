
/*
 * Problem statement :- https://leetcode.com/problems/two-sum/description/
 *
 */
 
#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        map<int, int> store;
        vector<int> ans;
        while(i < nums.size()){
            int rem = target - nums[i];
            if(store.find(rem) != store.end()){
                ans.push_back(store[rem]);
                ans.push_back(i);
                return ans;
            }
            store[nums[i]] = i;
            i++;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    
};
