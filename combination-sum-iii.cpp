class Solution {
public:
    vector<vector<int>> res;
    void printVector(vector<int>& v) {
        for(auto n : v) 
            cout << n << " ";
        cout << endl;
    }
    void util(int k, int n, int nextElem, vector<int>& comb, int nextIndex, int countOfChosen, int sum) {
        if(countOfChosen == k) {
            if(sum == n) {
                //printVector(comb);
                res.push_back(comb);
            }
            return;
        }
        if(nextElem > 9) return;
       // cout << "util = " << nextElem << "\n";
        
        if(sum + nextElem <= n) {
            //cout << "util = choosen\n";
            comb[nextIndex] = nextElem;
            //printVector(comb);
            util(k, n, nextElem+1, comb, nextIndex+1, countOfChosen+1, sum+nextElem);
        }
        util(k, n, nextElem+1, comb, nextIndex, countOfChosen, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < 0) return res;
        if(k > 9) return res;
        vector<int> comb(k);
        if(k == 1) {
            if(n > 9) return res;
            else {
                comb[0] = n;
                res.push_back(comb);
                return res;
            }
        }
        if(n == 1) { // k > 1
            return res;
        }
        util(k, n, 1, comb, 0, 0, 0);
        return res;        
    }
};
