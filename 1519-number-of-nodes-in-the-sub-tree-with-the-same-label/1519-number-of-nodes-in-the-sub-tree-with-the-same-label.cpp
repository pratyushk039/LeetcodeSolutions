#define um unordered_map<int,vector<int>>
class Solution {
public:
    void dfs(int curr,vector<vector<int>>& gr,vector<int>&vis,string &labels,um &map){
        vis[curr]=1;
        int leaf=0;
        //---------------------------------
        for(int nbr:gr[curr]){if(vis[nbr]==0){leaf=1;break;}}
        if(leaf==0){
            vector<int> v(26,0);
            v[labels[curr]-'a']+=1;
            map[curr] = v;
            return;
        }
        //---------------------------------
        vector<int> curr_ans(26,0);
        curr_ans[labels[curr]-'a']+=1;
        for(int nbr:gr[curr]){
            if(vis[nbr]==0){
                dfs(nbr,gr,vis,labels,map);
                for(int i=0;i<26;i++){curr_ans[i]+=map[nbr][i];}
            }
        }
        map[curr]=curr_ans;
        return;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>ans(n);
        um map;
        vector<vector<int>>gr(n);
        vector<int> vis(n,0);
        for(auto v:edges){
            gr[v[0]].push_back(v[1]);
            gr[v[1]].push_back(v[0]);
        }
        dfs(0,gr,vis,labels,map);
        for(int i=0;i<n;i++){
            ans[i] = map[i][labels[i]-'a'];
        }
        return ans;
    }
};