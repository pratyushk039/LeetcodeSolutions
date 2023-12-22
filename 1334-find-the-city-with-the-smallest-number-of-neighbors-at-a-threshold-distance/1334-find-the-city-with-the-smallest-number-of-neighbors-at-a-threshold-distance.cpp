class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //trying floyd warshall 
        vector<vector<long long>> dp(n,vector<long long>(n,1ll*INT_MAX));
        for(int I=0;I<n;I++){dp[I][I]=0;}
        for(auto v:edges){
            dp[v[0]][v[1]]=v[2];dp[v[1]][v[0]]=v[2];
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans,mini=INT_MAX;
        for(int i=0;i<n;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold && dp[i][j]!=0){c+=1;}
            }
            if(c<=mini){ans=i;mini=c;}
        }
        return ans;
    }
};