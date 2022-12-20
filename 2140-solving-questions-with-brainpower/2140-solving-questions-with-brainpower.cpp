class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long> ans(n,1ll*q[n-1][0]);
        for(int i=n-2;i>-1;i--){
            long long x=0;
            if(q[i][1]+i+1<n){x=ans[q[i][1]+i+1];}
            ans[i]=max(1ll*(q[i][0]+x),ans[i+1]);
        }
        return ans[0];
    }
};