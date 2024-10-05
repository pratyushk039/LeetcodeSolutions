class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i:nums){sum+=i;}
        if(sum%2!=0){return false;}
        sum/=2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){dp[i][0]=true;}
        if(nums[0]<=sum)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<sum+1;j++){
                dp[i][j] = dp[i][j]||dp[i-1][j];
                if(dp[i-1][j]&&(nums[i]+j<=sum)){dp[i][nums[i]+j]=true;}
            }
        }
        return dp[n-1][sum];
    }
};