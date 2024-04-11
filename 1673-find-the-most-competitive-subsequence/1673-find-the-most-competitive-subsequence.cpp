class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size(),fin_size = k;
        k=n-k;
        stack<int> s,s1;
        for(int i=0;i<n;i++){
            while((k>0) && (!s.empty()) && (s.top()>nums[i])){s.pop();k-=1;}
            s.push(nums[i]);
        }
        while(!s.empty()){s1.push(s.top());s.pop();}

        vector<int> ans;
        while(!s1.empty() && ans.size()<fin_size){
            ans.push_back(s1.top());s1.pop();
        }
        return ans;
    }
};