class Solution {
public:
    int util(int curr ,vector<int>&arr ,vector<int>&dp,int k){
        int n = arr.size();
        if(curr>=n){return 0;}
        if(dp[curr]!=-1){return dp[curr];}
        int ans=0,add=arr[curr];
        for(int i=curr+1;i<min(n+1,curr+k+1);i++){
            add=max(add,arr[i-1]);
            ans = max(ans,add*(i-curr)+util(i,arr,dp,k));
        }
        return dp[curr]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return util(0,arr,dp,k);
    }
};