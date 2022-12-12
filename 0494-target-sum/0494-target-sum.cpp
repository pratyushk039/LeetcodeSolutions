class Solution {
public:
    int util(vector<int> &nums,int target,int idx,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx==n-1){
            if(target+nums[idx]==0 && target-nums[idx]==0){return dp[idx][target+1000]=2;}
            if(target+nums[idx]==0 || target-nums[idx]==0){return dp[idx][target+1000]=1;}
            return dp[idx][target+1000]=0;
        }
        if(dp[idx][target+1000]!=-1){return dp[idx][target+1000];}
        int x  =util(nums,target-nums[idx],idx+1,dp);
        int y = util(nums,target+nums[idx],idx+1,dp);
        return dp[idx][target+1000]=x+y;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3002,-1));
        int ans = util(nums,target,0,dp);
        return ans;
    }
};