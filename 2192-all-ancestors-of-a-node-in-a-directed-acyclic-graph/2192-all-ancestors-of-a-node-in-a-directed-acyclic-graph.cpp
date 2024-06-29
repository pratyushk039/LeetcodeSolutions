class Solution {
public:
    void dfs(int curr , vector<vector<int>>& gr , vector<set<int>>& ancs, vector<int> &vis){
        vis[curr]=1;
        int n=gr.size();
        set<int> temp;
        for(int nbrs : gr[curr]){
            if(vis[nbrs]==0){dfs(nbrs,gr,ancs,vis);}
            temp.insert(ancs[nbrs].begin(),ancs[nbrs].end());
            temp.insert(nbrs);
        }
        
        ancs[curr]=temp;
        
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ancs(n);
        vector<vector<int>> ans(n);
        vector<vector<int>> gr(n);
        vector<int> vis(n,0);
        for(auto vec :edges){
            gr[vec[1]].push_back(vec[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){dfs(i,gr,ancs,vis);}
        }
        for(int i=0;i<n;i++){
            auto iSet=ancs[i];
            for(auto &itr:iSet){
                ans[i].push_back(itr);
            }
        }
        return ans;
    }
};