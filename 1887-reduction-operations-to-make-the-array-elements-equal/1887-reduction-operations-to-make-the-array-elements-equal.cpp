class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> m;
        vector<int> pref;
        for(int i:nums){
            m[i]+=1;
        }
        if(m.size()==1){return 0;}
        for(auto itr:m){
            pref.push_back(itr.second);
        }
        int n =pref.size();
        reverse(pref.begin(),pref.end());
        int ans=pref[0];
        for(int i=1;i<n-1;i++){
            pref[i]+=pref[i-1];
            ans+=pref[i];
        }
        return ans;
    }
};