#define um unordered_map
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        s+=" ";
        string k="";
        for(auto ch:s){
            if(ch==' '){
                v.push_back(k);
                k="";
                continue;
            }
            k+=ch;
        }
        um<char,string>map;
        unordered_set<string> set;
        if(v.size()!=pattern.size()){return false;}
        int idx=0;
        for(auto ch:pattern){
            if(map.find(ch)!=map.end()){
                if(map[ch]!=v[idx]){return false;}
                else{idx+=1;}
            }
            else{
                if(set.find(v[idx])==set.end()){map[ch] = v[idx];set.insert(v[idx]);idx+=1;}
                else{return false;}
            }
        }
        return true;
    }
};