class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){return a.second>b.second;}
        return a.first<b.first;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> nums(n);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            nums[i].first=nums2[i];nums[i].second=nums1[i];
        }
        sort(nums.begin(),nums.end(),comp);
        long long ksum=0ll;for(int i=n-k;i<n;i++){ksum+=1ll*nums[i].second;pq.push(nums[i].second);}
        long long ans=1ll*(nums[n-k].first)*(ksum);
        for(int i=n-k-1;i>-1;i--){
            if(nums[i].second>pq.top()){ksum+=nums[i].second-pq.top();pq.pop();pq.push(nums[i].second);}
            ans=max(ans,1ll*(nums[i].first)*(ksum));
        }
        return ans;
    }
};