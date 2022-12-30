#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void dfs(vvi &ans,vi &path,int curr,vi &vis,vvi &gr){
        int n = gr.size();
        path.push_back(curr);
        if(curr==n-1){ans.push_back(path);path.pop_back();return;}
        vis[curr]=1;
        for(int nbr:gr[curr]){
            if(vis[nbr]==0){
                dfs(ans,path,nbr,vis,gr);
            }
        }
        path.pop_back();
        vis[curr]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vvi ans;
        int n = graph.size();
        vi path,vis(n,0);
        dfs(ans,path,0,vis,graph);
        return ans;
    }
};