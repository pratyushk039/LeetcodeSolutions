class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){return a[1]<b[1];}
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n = pairs.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=1+ans;
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};