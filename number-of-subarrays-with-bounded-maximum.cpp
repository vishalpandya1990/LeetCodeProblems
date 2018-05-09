class Solution {
public:
    int numSubarrayBoundedMax_bruteForce(vector<int>& A, int L, int R) {
        int n = A.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int maxn = A[i];
            for(int j = i; j < n; j++) {
                if(A[i] > R) break;
                maxn = max(maxn, A[j]);
                if(maxn >= L && maxn <= R) // not necessary
                    count++; 
            }
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int count = 0;
        int countOfSubArraysEndingAtLastPosition = 0;
        int previousInvalidIndex = -1;
        for(int i = 0; i < n; i++) {
            if(A[i] > R) {
                countOfSubArraysEndingAtLastPosition = 0;
                previousInvalidIndex = i;
            } else if(A[i] < L) {
                count += countOfSubArraysEndingAtLastPosition;
            } else {
                countOfSubArraysEndingAtLastPosition = i - previousInvalidIndex;
                count += countOfSubArraysEndingAtLastPosition;
            }
        }
        return count;
    }
};
