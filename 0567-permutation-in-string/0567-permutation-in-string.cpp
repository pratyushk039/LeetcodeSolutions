class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m>n){return false;}
        vector<int> window(26,0),fix(26,0);
        for(char c:s1){
            fix[c-'a']+=1;
        }
        for(int i=0;i<m;i++){
            window[s2[i]-'a']+=1;
        }
        if(window==fix){return true;}
        for(int i=1;i<=n-m;i++){
            window[s2[i-1]-'a']-=1;
            window[s2[i+m-1]-'a']+=1;
            if(window==fix){return true;}
        }
        return false;
    }
};