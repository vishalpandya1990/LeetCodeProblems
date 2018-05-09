class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n-1, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize == 0) return false;
        
        int colSize = matrix[0].size();
        if(colSize == 0) return false;
        
        if(target < matrix[0][0]) return false;
        if(target > matrix[rowSize-1][colSize-1]) return false;
        
        int i;
        for(i = 0; i < rowSize; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][colSize-1])
                break;
        }
        if(i == rowSize) return false;
        int idx = binarySearch(matrix[i], target);
        return idx == -1 ? false : true;
    }
};
