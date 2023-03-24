class Solution {
public:
    void util(vector<int>& nums, int k,int idx, int bitmask,int &ans){
        int n = nums.size();
        if(idx==n){
            if(bitmask!=0){ans+=1;}
            return;
        }
        bool can=true;
        int curr=nums[idx];
        for(int i=0;i<21;i++){
            int mask = (1<<i);
            if(((mask)&(bitmask)) !=0){
                if(abs(curr-nums[i])==k){can=false;break;}
            }
        }
        if(!can){util(nums,k,idx+1,bitmask,ans);}
        else{
            util(nums,k,idx+1,bitmask,ans);
            util(nums,k,idx+1,(bitmask)|(1<<idx),ans);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n= nums.size();
        int ans=0;
        util(nums,k,0,0,ans);
        return ans;
    }
};