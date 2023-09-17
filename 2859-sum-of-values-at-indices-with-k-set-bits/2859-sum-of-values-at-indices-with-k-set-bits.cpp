class Solution {
public:
    int setk(int i, int k){
        int ans=0;
        for(int j=0;j<31;j++){
            if((1<<j)&i){ans+=1;}
        }
        return ans==k;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(setk(i,k)){ans+=nums[i];}
        }
        return ans;
    }
};