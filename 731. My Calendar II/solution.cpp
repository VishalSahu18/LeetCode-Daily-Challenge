class MyCalendarTwo {
public:   
   map<int,int>map;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
     map[start]++;
     map[end]--;    
     int book = 0;
        
     for(auto it = map.begin();it!=map.end();it++){
         
         book+= it->second;
         
         if(book==3){
             map[start]--;
             map[end]++;
             return false;
         }
         
     }       
        return true; 
    }
};
