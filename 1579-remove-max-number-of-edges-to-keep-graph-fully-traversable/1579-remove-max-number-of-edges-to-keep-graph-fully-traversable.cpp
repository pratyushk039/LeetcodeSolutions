class UnionFind{
    public:
    vector<int> parent,rrank;
    UnionFind(int n){
        rrank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){parent[i]=i;}
    }
    int find(int x){
        if(x==parent[x]){return x;}
        return parent[x] = find(parent[x]);
    }
     void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rrank[rootX] > rrank[rootY]) {
                parent[rootY] = rootX;
            } else if (rrank[rootX] < rrank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rrank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n+1),ufb(n+1);
        unordered_set<int> s;
        int m = edges.size();
        for(int i=0;i<m;i++){
            auto e = edges[i];
            if(e[0]==3 && (ufa.find(e[1])!=ufa.find(e[2]))){ufa.merge(e[1],e[2]);ufb.merge(e[1],e[2]);s.insert(i);}
        }
        //alice
        for(int i=0;i<m;i++){
            auto e = edges[i];
            if(e[0]==1 && (ufa.find(e[1])!=ufa.find(e[2]))){
                ufa.merge(e[1],e[2]);
                s.insert(i);
            }
        }
        //bob
        for(int i=0;i<m;i++){
            auto e = edges[i];
            if(e[0]==2 && (ufb.find(e[1])!=ufb.find(e[2]))){
                ufb.merge(e[1],e[2]);
                s.insert(i);
            }
        }
        
        set<int> s1,s2;
        for(int i=1;i<=n;i++){s1.insert(ufa.find(i));}
        if(s1.size()>1)return -1;
        for(int i=1;i<=n;i++){s2.insert(ufb.find(i));}
        if(s2.size()>1)return -1;
            
        return m - s.size();
        
    }
};