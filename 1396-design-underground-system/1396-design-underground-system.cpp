class UndergroundSystem {
public:
    unordered_map<string,pair<double,int>> avg_map;
    unordered_map<int,pair<string,int>> ck_in_t;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ck_in_t[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = ck_in_t[id].first;
        int t1 = ck_in_t[id].second;
        ck_in_t.erase(id);
        string x = startStation+'$'+stationName;
        if(avg_map.find(x)==avg_map.end()){avg_map[x] = {1.0*t-t1,1};}
        else{
            double y = avg_map[x].first,n = avg_map[x].second;
            avg_map[x] = {(y*n+t-t1)/(n+1),n+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string x = startStation+'$'+endStation;
        return avg_map[x].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */