class Solution {
public:
    // first the non constant space solution.
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,0);
        for(int i:nums){
            if(i>=1 && i<=n){v[i]=1;}
        }
        for(int i=1;i<=n;i++){if(v[i]==0){return i;}}
        return n+1;
    }
};