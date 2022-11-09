#define us unordered_set
class Solution {
public:
    int numSplits(string s) {
        us<char> back,forw;
        int n = s.size(),ans=0;
        vector<int> uniq(n);
        for(int i=n-1;i>-1;i--){
            back.insert(s[i]);
            uniq[i]=back.size();
        }
        for(int i=0;i<n-1;i++){
            forw.insert(s[i]);
            if(forw.size()==uniq[i+1]){ans+=1;}
        }
        return ans;
    }
};