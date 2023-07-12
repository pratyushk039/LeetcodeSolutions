class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<int> &truth, vector<int> &tnl, int curr,unordered_map<int,int> &vis){
        vis[curr]=1;
        if(tnl[curr]==1){
            truth[curr]=1;
            return 1;
        }
        int tr=1;
        for(int nb:graph[curr]){
            if(truth[nb]==-1 && vis[nb]==0){truth[nb]=dfs(graph,truth,tnl,nb,vis);}
            else if(truth[nb]==-1 && vis[nb]==1){truth[nb]=0;}//cycle finding
            tr*=truth[nb];
            if(tr==0) break;
        }
        truth[curr]=tr;
        return tr;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>tnl(n,0);
        vector<int> truth(n,-1);
        unordered_map<int,int> vis;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){tnl[i]=1;}
            vis[i]=0;
        }
        for(auto itr:vis){
            if(itr.second==0){dfs(graph,truth,tnl,itr.first,vis);}
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(truth[i]==1){ans.push_back(i);}
        }
        return ans;
    }
};