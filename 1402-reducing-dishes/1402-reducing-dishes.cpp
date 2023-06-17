#define vi vector<int>
class Solution {
public:
    int maxSatisfaction(vector<int>& S) {
        int n = S.size();
        sort(S.begin(),S.end());
        vector<vi> dp(501,vi(501,-INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
            dp[i][1] = S[i];
        }
        for(int i=1;i<n;i++){
            for(int j=2;j<=i+1;j++){
                if(dp[i-1][j-1]==-INT_MAX && dp[i-1][j]==-INT_MAX){continue;}
                dp[i][j] = max(j*S[i]+dp[i-1][j-1],dp[i-1][j]);
            }
        }
        vi arr = dp[n-1];
        return *max_element(arr.begin(),arr.end());
    }
};