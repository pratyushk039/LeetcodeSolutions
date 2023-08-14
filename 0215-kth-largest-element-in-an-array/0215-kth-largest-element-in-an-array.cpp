class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> s;
        for(auto i:nums){s.push(i);}
        int i=0;
        while(i<=k){
            i++;
            int itr = s.top();s.pop();
            if(i==k){return itr;}
        }
        return 0;
    }
};