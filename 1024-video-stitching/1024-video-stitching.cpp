class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int n = clips.size();
        vector<int> dp(n,INT_MAX);
        for(int i=n-1;i>-1;i--){
            auto v = clips[i];
            if(v[0]>time){continue;}
            if(v[1]>=time && v[0]<=time){dp[i]=1;continue;}
            //dp[i] is the answer for clips[i][0] onwards.
            for(int j=i+1;j<n;j++){
                auto x = clips[j];
                //have taken v, trying to see if x gives min.
                if(x[0]<=v[1] && x[1]>v[1]){dp[i]=min(dp[i],dp[j]);}
            }
            if(dp[i]!=INT_MAX)dp[i]+=1;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(clips[i][0]!=0){continue;}
            ans=min(ans,dp[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};