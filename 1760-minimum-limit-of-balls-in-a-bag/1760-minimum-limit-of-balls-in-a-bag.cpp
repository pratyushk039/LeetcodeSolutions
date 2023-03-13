class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int lo=1,hi=1e9;
        while(lo<hi){
            int mid = (lo+hi)/2;
            long long operations=0ll;
            for(int i=0;i<n;i++){
                operations += 1ll*ceil(1.0*nums[i]/mid);
            }
            operations-=n;
            if(operations<=maxOperations){hi=mid;}
            else{lo=mid+1;}
        }
        return lo;
    }
};