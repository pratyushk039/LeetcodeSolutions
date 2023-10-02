class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int score = *max_element(nums.begin(),nums.end());
        int ans=0,cn=0;
        nums.push_back(-1);
        for(auto i:nums){
            if(i!=score){ans=max(ans,cn);cn=0;}
            else{cn+=1;}
        }
        return ans;
    }
};