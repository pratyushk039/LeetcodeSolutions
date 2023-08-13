class Solution {
public:
    vector<int> dp;
    int util(vector<int>& nums, int idx){
        int n = nums.size();
        if(idx==n){return 1;}
        if(dp[idx]!=-1){return dp[idx];}
        int a=0,b=0,c=0;
        if(idx+1<n){
            if(nums[idx]==nums[idx+1]){a=util(nums,idx+2);}
        }
        if(idx+2<n){
            if((nums[idx]==nums[idx+1]) && (nums[idx+1]==nums[idx+2])){b = util(nums,idx+3);}
            if((nums[idx]+1==nums[idx+1]) && (nums[idx+1]+1==nums[idx+2])){c = util(nums,idx+3);}
            
        }
        return dp[idx] = (a+b+c)==0?0:1;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        bool ans=false;
        ans= util(nums,0)==0?false:true;
        return ans;
    }
};