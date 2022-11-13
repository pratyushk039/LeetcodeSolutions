class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        s.push(nums[0]);
        int del = 0;
        for(int i=1;i<n;i++){
            int idx = s.size();
            if(idx%2!=0 && s.top()==nums[i]){del+=1;continue;}
            s.push(nums[i]);
        }
        return (n-del)%2==0?del:del+1;
    }
};