class Solution {
public:
    long fact(int n) {
        if(n <= 1) return 1;
        else return n*fact(n-1);
    }
    int binomialCoeff(int n, int k)
    {
        int C[k+1];
        memset(C, 0, sizeof(C));
 
        C[0] = 1;  // nC0 is 1
 
        for (int i = 1; i <= n; i++)
        {
            // Compute next row of pascal triangle using
            // the previous row
            for (int j = min(i, k); j > 0; j--)
                C[j] = C[j] + C[j-1];
        }
        return C[k];
    }
    int uniquePaths(int m, int n) {
        if(m == 1) return 1;
        if(n == 1) return 1;
        //long n1 = fact(m+n-2);
        //long n2 = fact(m-1);
        //long n3 = fact(n-1);
       //return n1 / (n2 * n3);
        return binomialCoeff(m+n-2, m-1);
    }
};
