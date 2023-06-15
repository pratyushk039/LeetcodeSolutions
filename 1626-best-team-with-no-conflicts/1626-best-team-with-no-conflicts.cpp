#define vi vector<int>
class Solution {
public:
    static bool comp(vi &a, vi&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vi> merged(n);
        vi dp(n);
        for(int i=0;i<n;i++){merged[i]={ages[i],scores[i]};}
        sort(merged.begin(),merged.end(),comp);
        int ans = 0;
        for(int i=0;i<n;i++){
            int score = merged[i][1],maximum = score,age = merged[i][0];
            for(int j=0;j<i;j++){
                if(merged[j][1]>score){continue;}
                maximum = max(maximum,score+dp[j]);
            }
            dp[i] = maximum;
        }
        return *max_element(dp.begin(),dp.end());
    }
};