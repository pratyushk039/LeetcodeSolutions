class Solution {
public:
    vector<int> dp;
    bool check(string s,int j1, int j2){
        if(s[j1]=='0'){return false;}
        int n = s.size();
        int val=0;
        for(int i=0;i<=j2-j1;i++){
            int idx = j2-i,bm=(1<<i);
            val+=bm*(s[idx]-'0');
        }
        // cout<<j1<<" "<<j2<<" "<<val<<endl;
        while(val%5==0){val/=5;}
        return val==1;
    }
    int util(string s, int idx){
        int n=s.size();
        if(idx>=n){return 0;}
        if(dp[idx]!=INT_MAX) return dp[idx];
        int ans=INT_MAX;
        for(int i=idx;i<n;i++){
            if(check(s,idx,i)){
                ans=min(ans,util(s,i+1));
                // cout<<i+1<<" "<<util(s,i+1)<<endl;
            }
        }
        return dp[idx] = ans==INT_MAX?INT_MAX:1+ans;
        
        
    }
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        int n = s.size();
        dp.resize(n,INT_MAX);
        util(s,0);
        // for(auto k:dp){cout<<k<<endl;}
        return dp[0]==INT_MAX?-1:dp[0];
        
    }
};