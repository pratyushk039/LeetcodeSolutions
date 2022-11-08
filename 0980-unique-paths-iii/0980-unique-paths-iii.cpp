class Solution {
public:
    void util(vector<vector<int>> & board,int rstart,int cstart,vector<vector<int>> &vis,int &ans){
        int m = board.size(),n=board[0].size();
        
        if(board[rstart][cstart]==2){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==0 && vis[i][j]==0){return;}
                }
            }
            ans+=1;
            return;
        }
         vis[rstart][cstart]=1;
        //int l=0,r=0,u=0,d=0;
        //d
        if(rstart+1<m){
            if(vis[rstart+1][cstart]==0 && board[rstart+1][cstart]!=-1){
                util(board,rstart+1,cstart,vis,ans);
            }
        }
        //u
        if(rstart-1>-1){
            if(vis[rstart-1][cstart]==0 && board[rstart-1][cstart]!=-1){
                util(board,rstart-1,cstart,vis,ans);
            }
        }
        //l
        if(cstart-1>-1){
            if(vis[rstart][cstart-1]==0 && board[rstart][cstart-1]!=-1){
                util(board,rstart,cstart-1,vis,ans);
            }
        }
        //r
        if(cstart+1<n){
            if(vis[rstart][cstart+1]==0 && board[rstart][cstart+1]!=-1){
                util(board,rstart,cstart+1,vis,ans);
            }
        }
        vis[rstart][cstart]=0;
        return ;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int rstart,cstart,ans=0;        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){rstart=i;cstart=j;break;}
            }
        }
        util(grid,rstart,cstart,vis,ans);
        return ans;
    }
};