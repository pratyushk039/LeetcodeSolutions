class Solution {
public:
    vector<int> rank,parent;
    int find(int x){
        if(parent[x]==x){return x;}
        return parent[x] = find(parent[x]);
    }
    void uni(int x,int y){
        int parX=find(x),parY=find(y);
        if(rank[parX]>rank[parY]){parent[parY]=parX;}
        if(rank[parX]<rank[parY]){parent[parX]=parY;}
        if(rank[parX]==rank[parY]){parent[parY]=parX;rank[parX]++;}
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        rank.resize(n+1,1);
        parent.resize(n+1);
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){parent[i]=i;}
        for(auto v:roads){
            uni(v[0],v[1]);
        }
        int par = find(1);
        for(auto vec:roads){
            if(find(vec[0])==par){ans=min(ans,vec[2]);}
        }
        return ans;
    }
};