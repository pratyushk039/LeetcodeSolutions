class Solution {
public:
    int triangleNumber(vector<int>& num) {
        sort(num.begin(),num.end());
        int ans=0,n=num.size();
        if(n<3){return 0;}
        vector<int> nums;
        for(int x:num){if(x!=0){nums.push_back(x);}}
        n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans += lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin()-(j+1);
            }
        }
        return ans;
    }
};