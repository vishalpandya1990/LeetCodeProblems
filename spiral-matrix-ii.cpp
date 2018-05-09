class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if(n == 0) return res;
        if(n == 1) {
            res[0][0] = 1;
            return res;
        }
        int elem = 1;
        int colSize = n, rowSize = n;
        int rowmin = 0, rowmax = rowSize-1, colmin = 0, colmax = colSize-1;
        while(rowmin <= rowmax && colmin <= colmax) {
            int i, j;
            for(i = rowmin, j = colmin; j <= colmax; j++)
                res[i][j] = elem++;
            j--; // j <- colmax
            
            if(rowmax == rowmin) {
                rowmax--, rowmin++; colmax--, colmin++; // break;
                continue;
            }
            for(i = rowmin+1; i <= rowmax; i++)
                res[i][j] = elem++;
            i--; // i <- rowmax
            
            if(colmax == colmin) {
                rowmax--, rowmin++; colmax--, colmin++; // break;
                continue;
            }
            
            for(j = colmax-1; j >= colmin; j--)
                res[i][j] = elem++;
            j++; // j <- colmin
            for(i = rowmax-1; i > rowmin; i--)
                res[i][j] = elem++;
            rowmax--, rowmin++, colmax--, colmin++;
        }
        return res;

    }
};
