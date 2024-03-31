class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans =0 ;
        int n =  nums.size();
        nums.push_back(nums[n-1]);
        n = nums.size();
        int i=0;
        while(i<n){
            int l = 0;
            int j=i+1;
            for(;j<n;j++){
                if(nums[j]==nums[j-1]){l=j-i;break;}
                l=j-i+1;
            }
            ans+=1ll*l*(l+1)/2;
            i=j;
        }
        return ans;
    }
};