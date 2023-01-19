class Solution {
public:
    int nc(int x) {
        return x*(x-1)/2; 
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n, nums[0]);unordered_map<int, int> m;m[0]=0;
        for(int i=1;i<n;i++){pref[i]=pref[i-1]+
            nums[i];
                int x=(pref[i]%k);x=x<0?x+k:x;m[x]+=1;}
        int y=(pref[0]%k);y=y<0?y+k:y;m[y]+=1;
        
        int ans = m[0];
        for(auto it:m){ans+=nc(it.second);}return ans;
    }
};