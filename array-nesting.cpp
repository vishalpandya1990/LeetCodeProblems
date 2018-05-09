class Solution {
public:
    int getNextUnvisited(bool visited[], int n) {
        int i;
        for(i = 0; i < n; i++) {
            if(visited[i] == false)
                return i;
        }
        return -1;
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        int maxLen = 0;
        while(1) {
            int idx = getNextUnvisited(visited, n);
            if(idx == -1)
                break;
            visited[idx] = true;
            s.insert(nums[idx]);
            while(s.find(nums[nums[idx]]) == s.end()) {
                idx = nums[idx];
                s.insert(nums[idx]);
                visited[idx] = true;
            }
            if(s.size() > maxLen) // unsigned comparison ****
                maxLen = s.size();
            s.clear();
        }
        return maxLen;
    }
};
