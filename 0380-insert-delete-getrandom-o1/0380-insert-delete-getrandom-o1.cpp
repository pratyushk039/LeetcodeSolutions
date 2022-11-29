class RandomizedSet {
public:
    unordered_map<int,int>map;
    vector<int> v,rem;
    int size=0;
    RandomizedSet() {
        rem.resize(2e5+1,-1);
    }
    
    bool insert(int val) {
        if(map.find(val)==map.end()){
            v.push_back(val);
            map[val]=size;
            rem[size]=0;
            size+=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.find(val)!=map.end()){
            rem[map[val]]=1;
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand()%size;
        while(rem[idx]!=0){
            idx = rand()%size;
        }
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */