class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0),vis(n,0);
        queue<int> q;
    for(int l=0;l<n;l++){
        if(vis[l]==0){
        q.push(l);
        color[l]=1;
        //cout<<l<<" ";
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
};