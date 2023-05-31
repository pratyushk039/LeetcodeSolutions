class Bitset {
public:
    int n_o,n_z,n;
    vector<int> bitset;
    unordered_map<int,char> map;//assigns meaning to bit values. saves us from traversing the array when flip is called
    Bitset(int n) {
        this->n=n;
        bitset.resize(n,0);
        map[0]='z';map[1]='o';
        n_o=0;n_z=n; //no. of ones = 0, no. of zeros =n initially.
    }
    
    void fix(int idx) {
        if(map[bitset[idx]]=='z'){
            bitset[idx]^=1;
            n_z-=1;
            n_o+=1;
        }
    }
    
    void unfix(int idx) {
        if(map[bitset[idx]]=='o'){
            bitset[idx]^=1;
            n_z+=1;
            n_o-=1;
        }
    }
    
    void flip() {
        swap(map[0],map[1]);
        swap(n_o,n_z);
    }
    
    bool all() {
        return n_o==n;
    }
    
    bool one() {
        return n_o>0;
    }
    
    int count() {
        return n_o;
    }
    
    string toString() {
        string s="";
        for(int i=0;i<n;i++){
            if(map[bitset[i]]=='z'){s.push_back('0');}
            else{s.push_back('1');}
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */