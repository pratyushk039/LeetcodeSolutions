class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[k-1]){nums[k]=nums[i];k+=1;}
        }
        return k;
    }
};