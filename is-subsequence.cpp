class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(ns > nt) return false;
        if(ns == 0) return true;
        if(ns == nt) {
            if(s.compare(t) == 0) return true;
            else 
                return false;
        }
        int i = 0, j = 0;
        bool ans = false;
        while(j < nt) {
            if(s[i] == t[j]) i++;
            j++;
            if(i == ns) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
