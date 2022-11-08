class Solution {
public:
    unordered_map<int,int> dp;
    int power(int x){
        int ans=0;
        int n= x;
        while(n>1){
            if(dp.find(n)!=dp.end()){return dp[x]=dp[n]+ans;}
            if(n%2==0){n/=2;}
            else{n=3*n+1;}
            ans+=1;
        }
        return dp[x]=ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i=lo;i<hi+1;i++){
            v.push_back({power(i),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};