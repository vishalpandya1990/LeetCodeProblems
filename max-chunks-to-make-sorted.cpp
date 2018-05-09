class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return n;
        int rightMin[n];
        rightMin[n-1] = INT_MAX;
        for(int i = n-2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i+1], arr[i+1]);
        }
        int count = 0, maxElemToLeft = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxElemToLeft = max(maxElemToLeft, arr[i]);
            if(rightMin[i] > maxElemToLeft) {
                count++;
            }
        }
        return count;
    }
};
