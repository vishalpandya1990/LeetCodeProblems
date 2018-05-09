class MyCalendarTwo {
public:
    map<int, int> m;
    MyCalendarTwo() {
        m = map<int, int>();
    }
    
    bool book(int start, int end) {
        if(m.find(start) != m.end())
            m[start]++;
        else 
            m[start] = 1;
        if(m.find(end) != m.end())
            m[end]--;
        else
            m[end] = -1;
        int curSum  = 0;
        for(auto p : m) {
            curSum += p.second;
            if(curSum >= 3) {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
