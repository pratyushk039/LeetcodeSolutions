class Solution {
public:
     static bool comp(vector<vector<int>> &a,vector<vector<int>> &b){
        return a[0]<b[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3));
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());
        dp[n-1] = jobs[n-1][2];
        for(int i=n-2;i>-1;i--){
            int iProfit = jobs[i][2];
            auto ptr = lower_bound(startTime.begin(),startTime.end(),jobs[i][1]);
            if(ptr!=startTime.end()){
                int len = ptr-startTime.begin();
                iProfit+=dp[len];
            }
            dp[i]=max(iProfit,dp[i+1]);
        }
        return dp[0];
    }
};