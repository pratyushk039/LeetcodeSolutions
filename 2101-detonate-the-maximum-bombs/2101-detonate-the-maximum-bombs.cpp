class Solution {
public:
    int dfs(vector<int> &vis,vector<vector<int>>& bombs,int i){
        int n=bombs.size();
        vis[i]=1;
        int ans=1;
        int x=bombs[i][0],y=bombs[i][1],r=bombs[i][2];
        for(int j=0;j<n;j++){
            if(i==j || vis[j]==1){continue;}
            int x1=bombs[j][0],y1=bombs[j][1];
            long long dist = pow(1ll*x-x1,2)+pow(1ll*y-y1,2);
            if(dist<=1ll*r*r){
                ans+=dfs(vis,bombs,j);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            ans=max(ans,dfs(vis,bombs,i));
        }
        return ans;
    }
};