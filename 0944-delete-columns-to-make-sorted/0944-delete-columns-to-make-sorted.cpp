class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(),n = strs[0].size(),del=0;
        vector<char> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(strs[j][i]);
            }
            vector<char> k = v;
            sort(k.begin(),k.end());
            if(k!=v){del+=1;}
            v.clear();
        }
        return del;
    }
};