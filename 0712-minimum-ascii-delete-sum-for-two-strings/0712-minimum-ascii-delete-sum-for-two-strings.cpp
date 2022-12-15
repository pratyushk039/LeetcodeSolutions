class Solution {
public:
    int minimumDeleteSum(string t1, string t2) {
        int m = t1.size(),n = t2.size();
        vector<int> suf1(m+1,0),suf2(n+1,0);
        for(int i=m-1;i>-1;i--){suf1[i] = suf1[i+1]+(int)t1[i]; }
        for(int i=n-1;i>-1;i--){suf2[i] = suf2[i+1]+(int)t2[i]; }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){dp[i][n]=suf1[i];}
        for(int i=0;i<=n;i++){dp[m][i] = suf2[i];}
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                if(t1[i]==t2[j]){dp[i][j]=dp[i+1][j+1];}
                else{
                    dp[i][j] = min((int)t1[i]+dp[i+1][j],(int)t2[j]+dp[i][j+1]);
                }
            }
        }
        return dp[0][0]; 
    }
};