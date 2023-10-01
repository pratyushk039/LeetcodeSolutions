class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int score =-1;
        for(int i:nums){score&=i;}
        if(score!=0){return 1;}
        int ans=0;
        int s=-1;
        for(int i=0;i<n;i++){
            s&=nums[i];
            if(s==0){s=-1;ans+=1;}
        }
        return ans;
    }
};