class Solution {
public:
    //i thought about what would happen if there was a 1 in the AND score. dividing that stream of 1's would result in an additional power of 2 added to the score. so if the score is non-zero, we have to take the whole array. thus return 1.
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