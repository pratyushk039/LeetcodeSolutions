class Solution {
public:
    //iteratively perfected my solution. one of the best problems to successfully solve!
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(),ans=0;
        unordered_map<int,int>map1,map2;
        vector<int> sums12,sums34;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sums12.push_back(nums1[i]+nums2[j]);
                sums34.push_back(nums3[i]+nums4[j]);
            }
        }
        for(int i=0;i<n*n;i++){
            map1[sums12[i]]+=1;
            map2[sums34[i]]+=1;
        }
        for(auto itr:map1){
            if(map2.find(-itr.first)!=map2.end()){
                ans+=itr.second*map2[-itr.first];
            }
        }
        return ans;
    }
};