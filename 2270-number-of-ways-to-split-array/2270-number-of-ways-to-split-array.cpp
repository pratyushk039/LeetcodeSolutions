class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1);
        int ans=0;
        pref[0] = 1ll*0;
        for(int i=1;i<=n;i++){pref[i]=pref[i-1]+nums[i-1];}
        for(int i=0;i<n-1;i++){
            long long av1=pref[i+1],av2=pref[n]-pref[i+1];
            if(av1>=av2){
                ans+=1;
            }
        }
        return ans;
        
    }
};