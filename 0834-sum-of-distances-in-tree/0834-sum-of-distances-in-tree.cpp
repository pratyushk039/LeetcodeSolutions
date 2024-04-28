//finally coded re-rooting !!
class Solution {
public:
    vector<vector<int>> gr;
    vector<int> subtree,res,ans;
    int n;
    void pre_dfs(int par,int curr){
        int subtree_v=1,res_v=0;
        for(int nbr:gr[curr]){
            if(nbr==par)continue;
            pre_dfs(curr,nbr);
            res_v+= res[nbr]+subtree[nbr];
            subtree_v += subtree[nbr];
        }
        subtree[curr] = subtree_v;
        res[curr] = res_v;
    }
    void main_dfs(int par,int curr){
        if(curr==0){ans[0] = res[0];}
        else{
            ans[curr] = ans[par] - subtree[curr] + this->n - subtree[curr];
                // one step closer to own subtree  //one step farther to everything else.
        }
        for(int nbr:gr[curr]){
            if(nbr==par)continue;
            main_dfs(curr,nbr);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        gr.resize(n);
        subtree.resize(n);
        res.resize(n);
        ans.resize(n);
        for(auto v:edges){
            gr[v[0]].push_back(v[1]);
            gr[v[1]].push_back(v[0]);
        }
        pre_dfs(-1,0);
        main_dfs(-1,0);
        return ans;
    }
};