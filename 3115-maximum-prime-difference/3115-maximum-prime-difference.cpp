class Solution {
public:
    
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size(),start=-1,end;
        set<int> s; s.insert(2); s.insert(3); s.insert(5); s.insert(7);
        for(int i=0;i<n;i++){
            if((s.find(nums[i])!=s.end()) ||  (nums[i]%2!=0 && nums[i]%3!=0 && nums[i]%5!=0 && nums[i]%7!=0 &&nums[i]!=1)){
                if(start==-1){start=i;end=i;}
                else{end=i;}
            }
        }
        return end-start;
    }
};