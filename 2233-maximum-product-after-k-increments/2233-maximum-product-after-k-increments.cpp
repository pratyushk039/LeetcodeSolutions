class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x:nums){pq.push(-x);}
        for(int i=0;i<k;i++){
            int y = pq.top();pq.pop();
            pq.push(y-1);
        }
        long long ans=1ll,mod=(1e9+7)*1ll;
        while(!pq.empty()){
            int z = -pq.top();pq.pop();
            ans = (ans*z)%mod;
        }
        return ans%mod;
    }
};