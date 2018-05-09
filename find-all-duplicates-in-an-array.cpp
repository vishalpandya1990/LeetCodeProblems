class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();
        vector<int> res;
        if(n <= 1) {
            return res;
        }
        for(int i = 0; i < n; i++) {
            int content = (a[i] % (n+1)) - 1;
            a[content] += (n+1);
        }
        for(int i = 0; i < n; i++) {
            int multiples = a[i] / (n+1);
            if(2 == multiples)
                res.push_back(i+1);
        }
        return res;        
    }
};
