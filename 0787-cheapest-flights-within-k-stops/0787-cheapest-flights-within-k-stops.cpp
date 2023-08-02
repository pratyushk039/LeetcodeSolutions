class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //bellman ford calculates the min path for upto i edges in path at the ith iteration.
        vector<int> dist(n,1e9);
        dist[src] = 0;
        for(int k=0;k<K+1;k++){
            vector<int> temp(dist);
            for(auto& v:flights){
                if( dist[v[0]]!=1e9 && temp[v[1]]>dist[v[0]]+v[2]){
                    temp[v[1]] = dist[v[0]]+v[2];
                }
            }
            dist=temp;
        }
        if(dist[dst]==1e9){return -1;}
        return dist[dst];
    }
};