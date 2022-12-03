class Solution {
public:
    string func(int k,char a){
        string s ="";
        for(int i=0;i<k;i++){
            s.push_back(a);
        }
        return s;
    }
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char i:s){
            map[i]+=1;
        }
        vector<pair<int,char>> v;
        for(auto itr:map){
            v.push_back({itr.second,itr.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string ans="";
        for(auto p:v){
            ans+=func(p.first,p.second);
        }
        return ans;
    }
};