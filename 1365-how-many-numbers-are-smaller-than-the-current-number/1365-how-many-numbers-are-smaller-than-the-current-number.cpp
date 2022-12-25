class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        vector<int> ans(n),vec=nums;
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            map[vec[i]] = lower_bound(vec.begin(),vec.end(),vec[i])-vec.begin();
        }
        for(int i=0;i<n;i++){
            ans[i] = map[nums[i]];
        }
        return ans;
    }
};