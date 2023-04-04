class Solution {
public:
    int partitionString(string s) {
        int n = s.size(),ans=1;
        unordered_set<char>set;
        for(int i=0;i<n;i++){
            if(set.find(s[i])!=set.end()){
                set.clear();
                set.insert(s[i]);
                ans+=1;
            }
            set.insert(s[i]);
        }
        return max(ans,1);
    }
};