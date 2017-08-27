
/*
 * Problem statement -https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 */
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char> st;
       int i = 0;
       int ans = 0;
       int n = s.length();
       int j = 0;
       while(i < n && j < n) {
            if(st.find(s.at(j)) != st.end()) {
                st.erase(s.at(i));
                i++;
            } else {
                ans = max(ans, j - i + 1);
                st.insert(s.at(j));
                j++;
            }
       }
       return ans; 
    }
};
