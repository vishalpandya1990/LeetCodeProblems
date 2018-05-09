class Solution {
public:
    int getLocalInversions(vector<int>& A) {
        int n = A.size();
        int count = 0;
        for(int i = 0; i < n-1; i++) {
            if(A[i] > A[i+1])
                count++;
        }
        return count;
    }
    int getGlobalInversions(vector<int>& A) {
        int n = A.size(), count = 0;
        if(n <= 1) return 0;
        for(int i = 1; i < n; i++) {
            int key = A[i];
            int j = i-1;
            while(j >= 0 && A[j] > key) {
                A[j+1] = A[j];
                j--;
                count++;
            }
            A[j+1] = key;
        }
        return count;
    }
    bool isIdealPermutation(vector<int>& A) {
        if(getLocalInversions(A) == getGlobalInversions(A))
            return true;
        return false;
    }
};
