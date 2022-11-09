class StockSpanner {
public:
    int size =-1;
    stack<int> s;
    unordered_map<int,int> map;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        size++;
        v.push_back(price);
        map[size]=1;
        while(!s.empty() && v[s.top()]<=price){
            map[size]+=map[s.top()];
            s.pop();
        }
        s.push(size);
        return map[size];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */