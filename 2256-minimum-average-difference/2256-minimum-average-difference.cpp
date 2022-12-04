class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1);
        int ans,mind=INT_MAX;
        pref[0] = 1ll*0;
        for(int i=1;i<=n;i++){pref[i]=pref[i-1]+nums[i-1];}
        for(int i=0;i<n;i++){
            int av1=pref[i+1]/(i+1),av2= i==n-1?0:(pref[n]-pref[i+1])/(n-i-1);
            if(abs(av1-av2)<mind){
                mind=abs(av1-av2);
                ans=i;
            }
        }
        return ans;
    }
};