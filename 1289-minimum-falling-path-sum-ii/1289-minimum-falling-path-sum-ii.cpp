class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mx) {
        int m = mx.size(),n=mx[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<n;i++){dp[m-1][i]=mx[m-1][i];}
        for(int i = m-2;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                int a = INT_MAX;
                for(int k=n-1;k>-1;k--){
                    if(k==j){continue;}
                    a=min(a,dp[i+1][k]);
                }
            dp[i][j] = a+mx[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){ans=min(ans,dp[0][i]);}
        return ans;
    }
};