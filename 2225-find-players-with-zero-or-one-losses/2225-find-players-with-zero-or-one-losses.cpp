class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> a,b;
        map<int,int> m;
        for(auto vec:matches){
            m[vec[1]]+=1;
            if(m.find(vec[0])==m.end()){m[vec[0]]=0;}
        }
        for(auto itr:m){
            if(itr.second==0){a.push_back(itr.first);}
            else if(itr.second==1){b.push_back(itr.first);}
        }
        return {a,b};
    }
};