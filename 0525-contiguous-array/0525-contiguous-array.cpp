class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),z=0,o=0,ans=0;
        vector<vector<int>> pref(n,vector<int>(2,0));
        pref[0][nums[0]]+=1;
        for(int i=1;i<n;i++){
            pref[i][nums[i]]=1+pref[i-1][nums[i]];
            pref[i][nums[i]^1]=pref[i-1][nums[i]^1];
            if(pref[i][0]==pref[i][1]){ans=i+1;}
            }
        unordered_map<int,int> m;
        for(int i=n-1;i>-1;i--){
            m[pref[i][0]-pref[i][1]]=max(i,m[pref[i][0]-pref[i][1]]);
        }
        for(int i=0;i<n;i++){
            ans=max(m[pref[i][0]-pref[i][1]]-i,ans);
        }
        return ans;
    }
};