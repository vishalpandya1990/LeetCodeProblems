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
    static bool myCompare(const Interval& it1, const Interval& it2) {
        return it1.start < it2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> res;
        if(n <= 1) {
            res = intervals;
            return res;
        }
        sort(intervals.begin(), intervals.end(), myCompare);
        int curStart = intervals[0].start, curEnd = intervals[0].end;
        for(int i = 1; i < n; i++) {
            int s = intervals[i].start;
            int e = intervals[i].end;
            if(s <= curEnd) {
                curEnd = max(curEnd, e);
            } else {
                Interval *newInterval = new Interval(curStart, curEnd);
                res.push_back(*newInterval);
                curStart = s;
                curEnd = e;
            }
        }
        Interval *newInterval = new Interval(curStart, curEnd);
        res.push_back(*newInterval);
        return res;
    }
};
