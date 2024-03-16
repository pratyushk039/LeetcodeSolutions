struct ComparePairs {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    }
};
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> numsd(nums);
        int n=nums.size(),m=q.size();
        long long sum=0;
        vector<long long> ans(m);
        set<std::pair<int, int>, ComparePairs> pq;
        for(int i=0;i<n;i++){
            pq.insert({nums[i],i});
            sum+=1ll*nums[i];
        }
        //cout<<"here";
        int fin=0;
        for(auto v:q){
            int idx=v[0],k=v[1];
            //mark
            if(nums[idx]>0){
            sum-=nums[idx];
            auto it = pq.find({nums[idx],idx});
            pq.erase(it);
            nums[idx]*=-1;
            }
            int cnt=0;
            while((pq.size()>0) && (cnt<k)){
                auto itf = pq.begin();
                auto pr = *itf;pq.erase(itf);
                sum-=pr.first;
                nums[pr.second]*=-1;
                cnt++;
            }
            ans[fin]=sum;fin++;
            
            
        }
        return ans;
    }
};