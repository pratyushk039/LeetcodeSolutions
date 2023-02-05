class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n =nums.size(),hi=1e9,lo=1;
        while(lo<=hi){
            int mid = (lo+hi)/2,temp=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){temp+=1;i++;}
            }
            if(temp>=k){hi=mid-1;}
            else{lo=mid+1;}
        }
        return lo;
    }
};