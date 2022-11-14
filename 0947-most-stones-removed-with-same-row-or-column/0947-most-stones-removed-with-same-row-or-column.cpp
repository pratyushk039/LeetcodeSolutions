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
    int removeStones(vector<vector<int>>& stones) {
        int ans=0;
        int n = stones.size();
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){parent[i]=i;}
        unordered_map<int,int> r,c;
        for(int i=0;i<n;i++){
            if(r.find(stones[i][0])==r.end()){r[stones[i][0]]=i;}
            else{
                Union(r[stones[i][0]],i);
            }
            if(c.find(stones[i][1])==c.end()){c[stones[i][1]]=i;}
             else{
                Union(c[stones[i][1]],i);
            }
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){m[find(i)]+=1;}
        ans = n-m.size();
        return ans;
    }
};