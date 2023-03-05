class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,sum=0,ans=INT_MAX;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>=target){
                ans=min(j-i+1,ans);
                sum-=nums[i];
                i+=1;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};