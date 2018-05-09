/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    typedef struct IntervalWrapper {
        Interval i;
        int index;
    } IntervalWrapper;
    static bool mycomp(const IntervalWrapper &it1, const IntervalWrapper &it2) {
        return it1.i.start < it2.i.start;
    }
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        IntervalWrapper intervalList[n];
        for(int ii = 0; ii < n; ii++) {
            intervalList[ii].i = intervals[ii];
            intervalList[ii].index = ii;
        }
        sort(intervalList, intervalList + n, mycomp);
        for(int j = 0; j < n; j++) {
            int k = j+1;
            while(k < n && intervalList[k].i.start < intervalList[j].i.end)
                k++;
            if(k != n) 
                res[intervalList[j].index] = intervalList[k].index;
        }
        return res;
    }
    vector<int> _findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        map<int, int> m;
        int index = 0;
        for(auto i : intervals) {
            m[i.start] = index++;
        }
        for(int i = 0; i < n; i++) {
            auto itr = m.lower_bound(intervals[i].end);
            if(itr != m.end())
                res[i] = itr->second;
        }
        return res;
    }
};
