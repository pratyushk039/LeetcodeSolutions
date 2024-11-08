class Solution {
public:
    int maxxor(int p, int maxbit){
        int  k = 0;
        for(int i=0;i<maxbit;i++){
            if((1<<i)&p){
                continue;
            }
            else{
                k|=(1<<i);
            }
        }
        return k;
    }
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        int n = nums.size();
        int last = n-1,all=0;
        vector<int> ans(n);
        for(auto x:nums){all^=x;}
        for(int i=0;i<n;i++){
            ans[i] = maxxor(all,m);
            all^=nums[last];last-=1;
        }
        return ans;
        
    }
};