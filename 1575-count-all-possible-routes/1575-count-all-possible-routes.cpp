class Solution {
public:
    vector<vector<int>> dp;
    vector<int> locations; 
    int st,fi,ful,n,mod;
    long long util(int idx,int fuel){
        if(dp[idx][fuel]!=-1){return dp[idx][fuel];}
        if(fuel==0){
            if(idx!=fi){return dp[idx][fuel]=0;}
            else{return dp[idx][fuel]=1;}
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==idx){continue;}
            if(abs(locations[idx]-locations[i])<=fuel){ans+=util(i,fuel-abs(locations[idx]-locations[i]));ans=ans%mod;}
        }
        if(idx==fi){return dp[idx][fuel]=(1+ans)%mod;}
        return dp[idx][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //assignments
        n = locations.size();
        st=start;fi=finish;ful=fuel;
        this->locations=locations;
        mod=1e9+7;
        dp.resize(n,vector<int>(fuel+1,-1));
        //
        
        return util(start,fuel)%mod;
    }
};