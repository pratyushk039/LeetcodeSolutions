class Solution {
public:
    vector<vector<int>> dp;
    int n;
    vector<int> n1,n2;
    int util(int bitmask,int idx){
        if(idx==n){return dp[idx][bitmask]=0;}
        if(dp[idx][bitmask]!=INT_MAX){return dp[idx][bitmask];}
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            
            if((bitmask&mask)==0){
                ans=min((n1[idx]^n2[i])+util((bitmask|mask),idx+1),ans);
            }
        }
        return dp[idx][bitmask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        n1=nums1;n2=nums2;
        dp.resize(n+1,vector<int>((1<<14),INT_MAX));
        util(0,0);
        return *min_element(dp[0].begin(),dp[0].end());
    }
};