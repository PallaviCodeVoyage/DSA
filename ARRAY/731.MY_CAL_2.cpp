class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int>mp;
    bool book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto it:mp)
        {
            sum=sum+it.second;
            if(sum>=3)//this means that before ending of an event another even has started which s valid till 2 overlapping but 3 here means the other two processe have started
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
