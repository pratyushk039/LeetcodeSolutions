class Solution {
public:
    vector<int> parent,rank;
    int n;
    int find(int x){
        if(parent[x]==x){return x;}
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int parx=find(x),pary=find(y);
        if(rank[parx]>rank[pary]){
            parent[pary] = parx;
        }
        else if(rank[parx]<rank[pary]){
            parent[parx] = pary;
        }
        else{
            parent[parx]=pary;
            rank[pary]+=1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        this->n = n;
        parent.resize(n);rank.resize(n,0);
        for(int i=0;i<n;i++){parent[i]=i;}
        for(auto vec:edges){Union(vec[0],vec[1]);}
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[find(i)]+=1;
        }
        vector<int> cluster,suffix; 
        for(auto itr:map){cluster.push_back(itr.second);}
        suffix.resize(cluster.size(),0);suffix[cluster.size()-1]=cluster[cluster.size()-1];
        long long ans=0;
        for(int i=cluster.size()-2;i>-1;i--){
            suffix[i] = suffix[i+1]+cluster[i];
            ans+=1ll*cluster[i]*suffix[i+1];
        }
        return ans;
    }
};