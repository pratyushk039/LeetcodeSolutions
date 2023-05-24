class Solution {
public:
    int numDistinct(string s, string t) {
        int ns=s.size(),nt=t.size();
        vector<vector<long>> dp(ns,vector<long>(nt,0));
        if(t[nt-1]==s[ns-1]){dp[ns-1][nt-1]=1;}
        vector<int> freq(ns,0);freq[ns-1]=dp[ns-1][nt-1];
        for(int i=ns-2;i>-1;i--){if(s[i]==t[nt-1]){freq[i]=1;} freq[i]+=freq[i+1];}
        for(int i=ns-2;i>-1;i--){
            for(int j=nt-1;j>-1;j--){
                if((s[i]!=t[j])){dp[i][j]=dp[i+1][j];}
                else{
                    int x = j<nt-1?dp[i+1][j+1]:freq[i];
                    dp[i][j]=j<nt-1?dp[i+1][j]+x:x;
                }
            }
        }
        return dp[0][0];
    }
};