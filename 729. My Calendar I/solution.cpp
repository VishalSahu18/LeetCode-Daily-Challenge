class MyCalendar {
public:

    set<pair<int,int>>st;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
        auto it  = st.lower_bound({start,end});
        
        if(it!=st.end() && !(end<=it->first) || it!=st.begin() && !(prev(it)->second<=start))
            return false;
        
        
        st.insert({start,end});
        return true;
        
    }
};