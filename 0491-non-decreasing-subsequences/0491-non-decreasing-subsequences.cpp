#define v vector
class Solution {
public:
    void util(set<v<int>>&ans,int idx,int prev,v<int>&nums,v<int>&sub){
        int n=nums.size();
        if(idx==n){
            if(sub.size()>1){ans.insert(sub);}
            return;
        }
        if(nums[idx]>=prev){
            sub.push_back(nums[idx]);
            util(ans,idx+1,nums[idx],nums,sub);
            sub.pop_back();
            util(ans,idx+1,prev,nums,sub);
        }
        else{
            util(ans,idx+1,prev,nums,sub);
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<v<int>>st;
        v<v<int>> ans;
        v<int> sub;
        int idx=0;
        for(int i:nums){
            idx+=1;
            sub.push_back(i);
            util(st,idx,i,nums,sub);
            sub.pop_back();
        }
        for(auto itr:st){
            ans.push_back(itr);
        }
        return ans;
    }
};