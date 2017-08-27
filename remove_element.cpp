
/*
 * Problem statement :- https://leetcode.com/problems/remove-element/description/
 */

class Solution {
public:
    int removeElement_verySlow(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int f, l, n = nums.size();
        for(f = 0; f < n && nums[f] != val; f++){}
        if(f > n-1) return n; //absent
        for(l = f + 1; l < n && nums[l] == val; l++){}
        int c = l - f;
        int to = f, from = l;
        while(from < n) {
            nums[to] = nums[from];
            to++;
            from++;
        }
        return n - c;
    }
    int removeElement_slow(vector<int>& nums, int val) {
        //copying "wanted" numbers
        int to = 0, from = 0;
        int n = nums.size();
        while(from < n){
            if(nums[from] != val){
                nums[to] = nums[from];
                to++;
            }
            from++;
        }
        return to;
    }
    int removeElement(vector<int>& nums, int val) {
        //removing "unwanted" numbers
        int n = nums.size();
        int last = n-1;
        int cur = 0;
        while(cur <= last){
            if(nums[cur] == val) {
                nums[cur] = nums[last];
                last--; //n--
            } else{
                cur++;
            }
        }
        return last+1;
    }
        
};
