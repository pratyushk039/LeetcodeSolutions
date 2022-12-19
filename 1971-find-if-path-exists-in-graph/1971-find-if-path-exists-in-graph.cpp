class Solution {
public:
    bool dfs(int n, vector<vector<int>>& gr, int curr, int d,vector<int> &v){
        v[curr]=1;
        if(curr==d){return true;}
        bool ans=false;
        for(int i:gr[curr]){
            if(v[i]==0){ans = ans || dfs(n,gr,i,d,v);}
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> v(n,0);
        vector<vector<int>> gr(n);
        for(auto vec:edges){
            gr[vec[0]].push_back(vec[1]);
            gr[vec[1]].push_back(vec[0]);
        }
        return dfs(n,gr,source,destination,v);
    }
};