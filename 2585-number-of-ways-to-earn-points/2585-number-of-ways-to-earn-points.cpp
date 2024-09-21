class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        //dp[i][j] = no. of ways to obtain j points using first i elements.
        //dp[i][j] = sum(dp[i-1][j-count*marks]), over count = 0 to count[i].
        int n = types.size(),ans=0,mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        //base case - i=0.
        for(int k=0;k<=types[0][0];k++){if(k*types[0][1]<=target)dp[0][k*types[0][1]]=1;}
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int cnt = types[i][0],score = types[i][1];
                for(int k=0;k<=cnt;k++){if(j-k*score>-1){dp[i][j]+=dp[i-1][j-k*score]%mod;dp[i][j]%=mod;}}
            }
        }
        // for(int i=0;i<n;i++){ans+=dp[i][target]%mod;ans%=mod;}
        ans = dp[n-1][target];
        return ans;
    }
};