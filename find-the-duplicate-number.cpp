class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        int n = N-1;
        for(int i = 0; i < N; i++) {
            int content = nums[i] % (n+20);
            nums[content] += n+20;
        }
        int i;
        for(i = 1 ; i <= n; i++) {
            int multiples = nums[i] / (n+20);
            if(multiples > 1) break;
        }
        return i;
    }
};
