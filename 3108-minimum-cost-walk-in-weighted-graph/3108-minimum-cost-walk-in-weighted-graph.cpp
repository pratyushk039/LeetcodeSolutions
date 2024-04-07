class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(x==parent[x]){return x;}
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int px = find(x),py=find(y);
        if(rank[px]>rank[py]){
            parent[py] = px;
        }
        else if(rank[py]>rank[px]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px]+=1;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){parent[i]=i;}
        vector<int> ans(query.size());
        unordered_map<int,int> andv;
        for(auto e:edges){Union(e[0],e[1]);}
        for(auto e:edges){andv[find(e[0])]=e[2];}
        
        //take component wise and:
        for(auto e:edges){andv[find(e[0])]&=e[2];}
        
        //ans queries
        for(int i=0;i<query.size();i++){
            if(query[i][0]==query[i][1]){ans[i]=0;continue;}//edge case.
            ans[i] = find(query[i][0])==find(query[i][1])?andv[find(query[i][0])]:-1;
        }
        return ans;
    }
};