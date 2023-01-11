class Solution {
public:
    int dfs( vector<vector<int>>& gr,vector<bool>& has,int curr,vector<bool>& vis){
        vis[curr]=true;
        int x=0,leaf=0,y;
        //leaf check
        for(int nbr:gr[curr]){
            if(!vis[nbr]){
                leaf+=1;
            }
        }
        if(leaf==0){
            if(has[curr]){return 0;}
            else return -1;
        }
        //-----------------------
        for(int nbr:gr[curr]){
            if(!vis[nbr]){
                y=dfs(gr,has,nbr,vis);
                if(y!=-1){x+=y+2;}
            }
        }
        if(x==0 && !has[curr]){return -1;}
        else{return x;}
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>gr(n);
        for(auto v:edges){
            gr[v[0]].push_back(v[1]);
            gr[v[1]].push_back(v[0]);
        }
        vector<bool>vis(n,false);
        return max(dfs(gr,hasApple,0,vis),0);
    }
};