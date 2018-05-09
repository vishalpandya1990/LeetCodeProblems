class MyCalendar {
public:
    MyCalendar() {
        events = vector<Interval>();
    }
    bool book(int start, int end) {
        int n = events.size();
        Interval ii(start, end);
        if(n == 0) {
            events.push_back(ii);
            return true;
        }
        int i;
        for(i = 0; i < n; i++) {
            if(events[i].start == start) return false;
            if(events[i].start > start) break;
        }
        if(i == n) {
            if(events[n-1].end <= start) {
                events.push_back(ii);
                return true;
            } else 
                return false;
        }
        if(i == 0) {
            if(end <= events[0].start) {
                events.insert(events.begin(), ii);
                return true;
            } else
                return false;
        }
        if(events[i-1].end <= start && events[i].start >= end) {
            events.insert(events.begin() + i, ii);
            return true;
        } else {
            return false;
        }
    }
private:
    typedef struct Interval {
        int start;
        int end;
        Interval(int s, int e) : start(s), end(e) {
            
        }
    } Interval;
    vector<Interval> events;
}; 

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
