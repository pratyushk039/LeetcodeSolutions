class Solution {
public:
    vector<int> nums;
    unordered_map<int,vector<int>> map;
    int n;
    Solution(vector<int>& nums) {
        this->nums=nums;
        n=this->nums.size();
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int m = map[target].size();
        int idx = rand()%m;
        return map[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */