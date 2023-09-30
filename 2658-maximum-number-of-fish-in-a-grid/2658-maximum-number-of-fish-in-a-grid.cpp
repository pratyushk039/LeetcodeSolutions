class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        int ans=0;
        ans+=grid[i][j];
        grid[i][j]*=-1;
        int m = grid.size(),n = grid[0].size();
        if(i+1<m && grid[i+1][j]>0){ans+=dfs(i+1,j,grid);}
        if(i-1>-1 && grid[i-1][j]>0){ans+=dfs(i-1,j,grid);}
        if(j+1<n && grid[i][j+1]>0){ans+=dfs(i,j+1,grid);}
        if(j-1>-1 && grid[i][j-1]>0){ans+=dfs(i,j-1,grid);}
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};