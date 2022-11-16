class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(),n = s2.size();
        if(s3.size()!=m+n){return false;}
        vector<vector<bool>> dp(m+1,vector<bool>(n+1));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0){continue;}
                bool a=false,b=false,c=true,d=true;
                if(i>0){
                    if(s1[i-1]!=s3[i+j-1]){c=false;}
                    if(s1[i-1]==s3[i+j-1]){ a = dp[i-1][j];}}
                if(j>0){
                    if(s2[j-1]!=s3[i+j-1]){d=false;}
                    if(s2[j-1]==s3[i+j-1]){ b = dp[i][j-1];}}
                if(c==false && d==false){dp[i][j]=false;continue;}
                dp[i][j] = a||b;
            }
        }
        return dp[m][n];
    }
};