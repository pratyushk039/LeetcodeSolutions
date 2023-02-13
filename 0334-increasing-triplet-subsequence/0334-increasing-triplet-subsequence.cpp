class Solution {
public:
    //hint : a soln springs to mind : compare len of lis to 3. discarded due to n^2 complexity. But here, only 2 numbers have to be compared with every new element.
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int comp1=INT_MAX,comp2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=comp1){comp1=nums[i];}
            else if(nums[i]<=comp2){comp2=nums[i];}
            else{return true;}
        }
        return false;
    }
};