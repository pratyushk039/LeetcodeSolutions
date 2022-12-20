class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=-INT_MAX,n=values.size();
        vector<int> pref(n),v(n);
        for(int i=0;i<values.size();i++){
            v[i]=i+values[i];
        }
        pref[n-1] = values[n-1]-n+1;
        for(int i=n-2;i>-1;i--){
            pref[i] = max(pref[i+1],values[i]-i);
            ans=max(ans,pref[i+1]+v[i]);
        }
        return ans;
    }
};