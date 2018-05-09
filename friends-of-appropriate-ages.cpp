class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int count = 0;
        int freq[121] = {0};
        for(auto age : ages)
            freq[age]++;
        for(int a = 0; a <= 120; a++) {
            int countA = freq[a];
            for(int b = 0; b <= 120; b++) {
                int countB = freq[b];
                int lowerBound = a/2 + 7;
                if((b > lowerBound) && (b <= a) && (a >= 100 || b <= 100)) {
                    count += countB * countA;
                    if(a == b)
                        count -= countA;
                }
            }
        }
        return count;
    }
};
