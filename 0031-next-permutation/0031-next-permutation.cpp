class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //find greatest k such that nums[k]<nums[k+1]. Reverse the array if not found and Done.
        int k = n-2;
        for(;k>-1;k--){if(nums[k]<nums[k+1]){break;}}
        if(k<0){reverse(nums.begin(),nums.end()); return;}
        // find max l such that l>k and nums[l]>nums[k]. swap nums[l] and nums[k], and swap nums[k+1:]
        int l = n-1;
        for(;l>k;l--){
            if(nums[l]>nums[k]){swap(nums[k],nums[l]);break;}
        }
        reverse(nums.begin()+k+1,nums.end());
        return;
    }
};