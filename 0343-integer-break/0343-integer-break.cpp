class Solution {
public:
    int util(int n,vector<int>&dp){
        if(dp[n]!=-1){return dp[n];}
        int ans=n;
        for(int i=1;i<n;i++){
            int x = util(n-i,dp);
            int y = util(i,dp);
            ans = max(ans,x*y);
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int> dp(59,-1);
        int ans = -INT_MAX;
        for(int i=1;i<n;i++){
            ans=max(ans,util(n-i,dp)*util(i,dp));
        }
        return ans;
    }
};