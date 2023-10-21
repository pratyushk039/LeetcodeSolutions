class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int n = nums.size(),ans = nums[n-1];
        dq.push_front({nums[n-1],n-1});
        for(int i=n-2;i>-1;i--){
            //defined the window for i
            while(!dq.empty() && dq.back().second-i>k){dq.pop_back();}
            
            int val = nums[i];ans = max(ans,val);
            if(dq.size()==0){dq.push_front({val,i});continue;}
            val += max(dq.back().first,0);ans = max(ans,val);
            int temp = dq.front().first;
            //maintaining monotonicity of queue
            while(!dq.empty() && temp<val){dq.pop_front();temp = dq.empty()?0:dq.front().first;}
            //inserting ith
            dq.push_front({val,i});
        }
        return ans;
    }
};