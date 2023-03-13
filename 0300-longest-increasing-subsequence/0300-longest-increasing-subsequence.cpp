class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            int len = 0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){len=max(dp[j],len);}
            }
            dp[i] = 1+len;
        }
        return *max_element(dp.begin(),dp.end());
    }
};