class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> smap,tmap;
        for(int i=0;i<t.size();i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        int ans=0;
        for(auto itr:smap){
            ans+=max(0,itr.second - tmap[itr.first]);
        }
        return ans;
    }
};