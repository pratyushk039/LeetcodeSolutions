class Solution {
public:
    int util(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        int m=grid.size(),n=grid[0].size();
        //base case
        if(row==m){
            return col;
        }
        if(grid[row][col]==1 && col+1<n && grid[row][col+1]!=-1){
            if(dp[row][col]==200){dp[row][col]=util(grid,dp,row+1,col+1);}
            return dp[row][col];
        }
        else if(grid[row][col]==-1 && col-1>=0 && grid[row][col-1]!=1){
            if(dp[row][col]==200) {dp[row][col]=util(grid,dp,row+1,col-1);}
            return dp[row][col];
        }
        else{
            dp[row][col]=-1;
            return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,200));// column can never be 200,so a good placeholder.
        vector<int> ans;
        for(int i=0;i<n;i++){
            int col =util(grid,dp,0,i);
            ans.push_back(col);
        }
        return ans;
    }
};