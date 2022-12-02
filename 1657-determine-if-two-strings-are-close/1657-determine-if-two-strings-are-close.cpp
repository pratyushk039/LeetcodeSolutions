class Solution {
public:
    bool closeStrings(string s, string t) {
        int m = s.size(),n=t.size();
        if(m!=n){return false;}
        sort(s.begin(),s.end());sort(t.begin(),t.end());
        if(s==t){return true;}
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<n;i++){
            v1[s[i]-'a']+=1;
            v2[t[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){if((v1[i]==0 || v2[i]==0) && !(v1[i]==0 && v2[i]==0)){return false;}}
        sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
        return v1==v2;
    }
};