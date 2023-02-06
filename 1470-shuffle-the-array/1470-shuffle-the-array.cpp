class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x = nums[i],y=nums[n+i];
            ans.push_back(x);ans.push_back(y);
        }
        return ans;
    }
};