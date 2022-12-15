class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size(),n = t2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                if(t1[i]==t2[j]){dp[i][j]=1+dp[i+1][j+1];}
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];    
    }
};