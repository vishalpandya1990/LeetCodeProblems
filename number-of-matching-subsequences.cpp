class Solution {
public:
    vector<set<string>> dp;
    vector<set<string>> inv;
    bool isPresentInCache(string p) {
        if(dp[p[0]-'a'].find(p) != dp[p[0]-'a'].end())
            return true;
        return false;
    }
    bool isPresentInInvalidCache(string p) {
        if(inv[p[0]-'a'].find(p) != inv[p[0]-'a'].end())
            return true;
        return false;
    }
    void addToCache(string p) {
        dp[p[0]-'a'].insert(p);
        return;
    }
    void addToInvalidCache(string p) {
        inv[p[0]-'a'].insert(p);
        return;
    }
    void printValidCache() {
        int i = 0;
        for(auto v : dp) {
            cout << i++ << " ";
            for(auto s : v)
                cout << s << " ";
            cout << endl;
        }
    }
    bool isSubsequence(string t, string p) {
        int nt = t.length();
        int np = p.length();
        if(nt < np) return false;
        if(nt == np) {
            if(t.compare(p) == 0) {
                addToCache(p);
                return true;
            } else {
                addToInvalidCache(p);
                return false;
            }
        }
        if(np == 1) {
            if(isPresentInCache(p))
                return true;
            else
                return false;
        }
        int i = 0, j = 0;
        bool ans = false;
        while (j < t.length()) {
            if (p[i] == t[j]) i++;
            j++;
            if (i == p.length()) {
                ans = true;
                break;
            }
        }
        if(ans)
            addToCache(p);
        else
            addToInvalidCache(p);
        return ans;
        /*
        bool ans;
        if(t[nt-1] == p[np-1]) { 
            ans = isSubsequence(t.substr(0, nt-1), p.substr(0, np-1));
            if(ans)
                addToCache(p);
            return ans;
        }
        ans = isSubsequence(t.substr(0, nt-1), p);
        if(ans)
            addToCache(p);
        return ans;
        */
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int ns = S.size();
        int nd = words.size();
        if(ns == 0 || nd == 0 ) return 0;
        dp = vector<set<string>>(26);
        inv = vector<set<string>>(26);
        for(char ch : S) {
            string tmp(1, ch);
            addToCache(tmp);
        }
        int count = 0;
        for(int i = 0; i < nd; i++) {
            if(isPresentInCache(words[i]))
                count++;
            else if(isPresentInInvalidCache(words[i]))
                continue;
            else if(isSubsequence(S, words[i]))
                count++;
        }
        return count;
    }
};
