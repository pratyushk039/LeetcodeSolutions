class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(),lo=1,hi=1e6;
        while(lo<hi){
            int mid  = (lo+hi)/2,sum=0;
            for(int i=0;i<n;i++){sum+=ceil(1.0*nums[i]/mid);}
            if(sum<=threshold){hi=mid;}
            else{lo=mid+1;}
        }
        return lo;
    }
};