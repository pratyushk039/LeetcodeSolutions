class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int j=0;j<nums.size();j++){
            int cnt=0,i=j;
            while(i!=0){
                cnt+=1;
                i=i&(i-1);
            }
            if(cnt==k){ans+=nums[j];}
        }
        return ans;
    }
};