class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>> &gr, vector<int>&dist,int n){
        set<pair<int,int>> s;
        s.insert({0,n});
        while(!s.empty()){
            auto front = s.begin();
            
            int curr = front->second;
            int distTill = front->first;
            s.erase(front);
            auto nbrV = gr[curr];
            for(auto pair:nbrV){
                int edge = pair.first;
                int nbr = pair.second;
                if(edge+distTill<dist[nbr]){
                    if(s.find({dist[nbr],nbr})!=s.end()){s.erase({dist[nbr],nbr});}
                    dist[nbr] = edge+distTill;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        return;
    }
    int dfs(int curr, vector<int>&dist,vector<vector<pair<int,int>>> &gr,int n,vector<int>&dp){
        if(curr==n){return 1;}
        if(dp[curr]!=-1){return dp[curr];}
        int mod =1e9+7;
        dp[curr]=0;
        for(auto pair:gr[curr]){
            int nbr = pair.second;
            if(dist[nbr]<dist[curr]){
                dp[curr]=(dp[curr]+dfs(nbr,dist,gr,n,dp))%mod;
            }
        }
        return dp[curr];
        
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> gr(n+1);
        vector<int> dist(n+1,INT_MAX),dp(n+1,-1);dist[n] =0;
        for(auto v:edges){
            gr[v[0]].push_back({v[2],v[1]});
            gr[v[1]].push_back({v[2],v[0]});
        }
        dijkstra(gr,dist,n);
        return dfs(1,dist,gr,n,dp);
    
    }
};