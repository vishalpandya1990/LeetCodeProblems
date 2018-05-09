class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        vector<int> res;
        if(rowSize == 0) return res;
        if(rowSize == 1) return res = matrix[0];
        int colSize = matrix[0].size();
        int rowmin = 0, rowmax = rowSize-1, colmin = 0, colmax = colSize-1;
        while(rowmin <= rowmax && colmin <= colmax) {
            int i, j;
            for(i = rowmin, j = colmin; j <= colmax; j++)
                res.push_back(matrix[i][j]);
            j--; // j <- colmax
            
            if(rowmax == rowmin) {
                rowmax--, rowmin++; colmax--, colmin++;
                continue;
            }
            for(i = rowmin+1; i <= rowmax; i++)
                res.push_back(matrix[i][j]);
            i--; // i <- rowmax
            
            if(colmax == colmin) {
                rowmax--, rowmin++; colmax--, colmin++;
                continue;
            }
            
            for(j = colmax-1; j >= colmin; j--)
                res.push_back(matrix[i][j]);
            j++; // j <- colmin
            for(i = rowmax-1; i > rowmin; i--)
                res.push_back(matrix[i][j]);
            rowmax--, rowmin++, colmax--, colmin++;
        }
        return res;
    }
};
