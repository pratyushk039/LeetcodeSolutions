class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefmin(n,nums[0]);
        for(int i=1;i<n;i++){
            prefmin[i] = min(prefmin[i-1],nums[i]);
        }
        set<int> s;
        s.insert(nums[n-1]);
        for(int j=n-2;j>0;j--){
            int numi = prefmin[j-1];
            s.insert(nums[j]);
            auto itk = s.lower_bound(nums[j]);
            if(itk!=s.begin()){itk--;}
            else{continue;}
            int numk = *itk;
            cout<<numi<<numk<<nums[j];
            if(numi<numk && numk<nums[j]){return true;}
        }
        return false;
    }
};