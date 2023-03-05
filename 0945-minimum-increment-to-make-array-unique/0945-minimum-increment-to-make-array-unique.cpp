class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ranges;//range will be monotonic
        map<int,int> map;
        for(int x:nums){map[x]+=1;}
        int start=1;
        for(auto itr:map){
            if(start==itr.first){start+=1;}
            else if(start<itr.first){
                ranges.push_back({start,itr.first-1});
                start=itr.first+1;
            }
        }
        int maxima = *max_element(nums.begin(),nums.end());
        ranges.push_back({maxima+1,maxima+n+1});
        //cout<<ranges[1][0];
        int st_idx = 0,ans=0;
        for(auto itr:map){
            while(map[itr.first]>1){
                if(ranges[st_idx][0]<itr.first){st_idx+=1;continue;}
                ans+=ranges[st_idx][0]-itr.first;
                ranges[st_idx][0]+=1;
                map[itr.first]-=1;
                if(ranges[st_idx][0]>ranges[st_idx][1]){st_idx+=1;}}
        }
        return ans;
    }
};