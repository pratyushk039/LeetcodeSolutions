class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> pref(n,1ll*differences[0]);
        int ans = 0;
        long long mini=pref[0],maxim=pref[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+differences[i];
            mini = min(mini,pref[i]);
            maxim = max(maxim,pref[i]);
        }
        for(int i =lower;i<=upper;i++){if(i+mini>=lower && i+maxim<=upper){ans+=1;}}
        return ans;
    }
};