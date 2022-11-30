class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i:arr){m[i]+=1;}
        unordered_set<int> s;
        for(auto itr:m){
            if(s.find(itr.second)!=s.end()){return false;}
            s.insert(itr.second);
        }
        return true;
    }
};