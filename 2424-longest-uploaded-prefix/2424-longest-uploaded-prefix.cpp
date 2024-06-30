class LUPrefix {
public:
    int n,pref;
     vector<int> up;
    LUPrefix(int n) {
        up.resize(n+1,0);
        this->n = n;
        pref=0;
    }
    
    void upload(int video) {
        up[video]  = 1;
        while(pref+1<=n){
            if(up[pref+1]==1){pref+=1;}
            else break;
        }
       
    }
    
    int longest() {
        return pref;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */