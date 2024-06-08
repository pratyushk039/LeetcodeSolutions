class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n,nums[0]%k);
        unordered_map<int,int> map;
        map[pref[0]] = 0;
        for(int i=1;i<n;i++){pref[i] = pref[i-1]+nums[i]; pref[i] = pref[i]%k;
                             if((map.find(pref[i])!=map.end() && (i-map[pref[i]])>1)||(pref[i]==0)){return true;}
                             else if(map.find(pref[i])==map.end()){map[pref[i]]=i;}
                            }
        return false;
        
    }
};