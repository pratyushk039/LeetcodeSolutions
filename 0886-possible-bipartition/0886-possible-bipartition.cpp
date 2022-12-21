class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0),vis(n,0);
        queue<int> q;
    for(int l=1;l<n;l++){
        if(vis[l]==0){
        q.push(l);
        color[l]=1;
        while(!q.empty()){
        int curr=q.front();q.pop();
        vis[curr]=1;
        for(int nb:graph[curr]){
            if(color[nb]==color[curr]){return false;}
            else if(vis[nb]==0){
                if(color[curr]==1){color[nb]=2;}
                else if(color[curr]==2){color[nb]=1;}
                q.push(nb);
            }
        }
    }
    }
    }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> gr(n+1);
        for(auto vec:dislikes){
            gr[vec[0]].push_back(vec[1]);
            gr[vec[1]].push_back(vec[0]);
        }
        return isBipartite(gr);
    }
};