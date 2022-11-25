class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        // i can only change 1 to zeroes , not zero to one. 
        //So, if there is a 1 at any number at ith place, i can always ensure that 1 occurs odd number of times at that position.
        int ans = 0;
        for(int i:nums){
            ans = (ans|i);
        }
        return ans;
    }
};