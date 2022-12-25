class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size(),n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> pref(n,nums[0]),ans(m);
        for(int i=1;i<n;i++){pref[i] = pref[i-1]+nums[i];}
        for(int i=0;i<m;i++){
            ans[i] = upper_bound(pref.begin(),pref.end(),queries[i])-pref.begin();
        }
        return ans;
    }
};