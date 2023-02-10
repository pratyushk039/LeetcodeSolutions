class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        //idx 0->negative,1->positive.
        vector<vector<int>> dp(2,vector<int>(n,-1));
        dp[0][0]=1;dp[1][0]=1;
        for(int i=1;i<n;i++){
            int pos_max=-INT_MAX,neg_max=-INT_MAX;
            for(int j=0;j<i;j++){
                if(nums[i]-nums[j]>0){pos_max=max(pos_max,dp[0][j]);}
                if(nums[i]-nums[j]<0){neg_max=max(neg_max,dp[1][j]);}
            }
            dp[1][i]=1+pos_max;
            dp[0][i]=1+neg_max;
        }
        int ans=-INT_MAX;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[0][i]);ans=max(ans,dp[1][i]);
        }
        return ans;
    }
};