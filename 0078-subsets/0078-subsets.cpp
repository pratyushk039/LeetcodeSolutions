#define pb push_back
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){temp.pb(nums[j]);}
            }
            ans.pb(temp);
        }
        return ans;
    }
};