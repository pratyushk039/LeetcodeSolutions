class Solution {
public:
    int util(vector<int>&prices , int idx,int amt,vector<vector<int>>&dp){
        int n  = prices.size();
        if(idx>=n){return 0;}
        if(dp[idx][amt+1]!=-1){return dp[idx][amt+1];}
        if(amt==-1){
            int x = util(prices,idx+1,prices[idx],dp);
            int y = util(prices,idx+1,-1,dp);
            return dp[idx][amt+1]=max(x,y);
        }
        if(amt>-1){
            return dp[idx][amt+1]=max(prices[idx]-amt+util(prices,idx+2,-1,dp),util(prices,idx+1,amt,dp));
        }
        return 0 ;
        
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(n==1){return 0;}
        vector<vector<int>> dp(n,vector<int>(1002,-1));
        return util(prices,0,-1,dp);
    }
};