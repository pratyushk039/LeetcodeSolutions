#define pb push_back
class Solution {
public:
    void util(string s,int i,vector<string>&ans){
        int n = s.size();
        if(i==n){ans.pb(s);return;}
        util(s,i+1,ans);
        if(s[i]>='a' && s[i]<='z'){s[i] = (char)(s[i]-32); util(s,i+1,ans);}
        else if(s[i]>='A' && s[i]<='Z'){s[i] = (char)(s[i]+32); util(s,i+1,ans);}
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        util(s,0,ans);
        return ans;
    }
};