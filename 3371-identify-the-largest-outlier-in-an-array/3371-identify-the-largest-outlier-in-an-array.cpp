class Solution {
    //lots of rust :(
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){sum+=nums[i];map[nums[i]]+=1;}
        
        for(int i=n-1;i>-1;i--){
            if((sum-nums[i])%2==0)map[nums[i]]-=1;
            if((sum-nums[i])%2==0 && map[(sum-nums[i])/2]>0){return nums[i];}
            if((sum-nums[i])%2==0)map[nums[i]]+=1;
        }
        return 1; //placeholder;
    }
};