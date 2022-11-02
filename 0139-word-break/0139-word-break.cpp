class Solution {
public:
    bool util(int curr , string &s, unordered_set<string>& wordDict, vector<int> &dp){
        int n = s.size();
        if(curr==n){return 1;}
        if(dp[curr] != -1){return dp[curr];}
        string sub = "";
        int ans = 0;
        for(int i =curr;i<n;i++){
            sub.push_back(s[i]);
            if(wordDict.find(sub)!=wordDict.end()){ans+=util(i+1,s,wordDict,dp);}
        }
        if(ans>0){dp[curr] = 1;}
        else if(ans==0){dp[curr]=0;}
        return dp[curr]==1?true:false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> w;
        for(auto st : wordDict){w.insert(st);}
        int n = s.size();
        vector<int> dp(n,-1);
        return util(0,s,w,dp);
    }
};