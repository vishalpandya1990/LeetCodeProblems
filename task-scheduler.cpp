class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        if(m == 0) return 0;
        if(m == 1) return 1;
        int freq[26] = {0}, next[26];
        memset(next , 0, sizeof(next));
        for(int i = 0; i < m; i++) {
            freq[tasks[i] -'A']++;
        }
        int time = 0, curTask = 0, count = 0;
        int rem = m;
        while(rem > 0) {
            if(freq[curTask] == 0) {
                curTask = (curTask+1)%26;
                continue;
            }
            if(next[curTask] > time) {
                count += next[curTask] - time;
                time = next[curTask];
            }
            count++;
            time++;
            next[curTask] += n+1;
            freq[curTask]--;
            curTask = (curTask+1)%26;
            rem--;
        }
        return count;
    }
};
