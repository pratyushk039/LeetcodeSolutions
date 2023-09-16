class Solution {
public:
    int swimInWater(vector<vector<int>>& heights) {
        int lo = 0,hi = 1e6+7,ans;
        int m = heights.size(), n = heights[0].size();
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            vector<vector<int>> vis(m,vector<int>(n,0));
            if(bfs(0,0,heights,mid,heights[0][0],vis)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    bool bfs(int i, int j,vector<vector<int>>& heights, int diff,int prev,vector<vector<int>>& vis){
        int m = heights.size(), n = heights[0].size();
        if(i>=m || j>=n || i<0 || j<0){return false;}
        if(vis[i][j]==1){return false;}
        if(prev>diff || heights[i][j]>diff){return false;}
        if(i==m-1 && j==n-1){return true;}
        
        vis[i][j]=1;
        
        bool a=false, b=false, c=false, d=false;
        a = bfs(i+1,j,heights,diff,heights[i][j],vis);
        b = bfs(i-1,j,heights,diff,heights[i][j],vis);
        c = bfs(i,j+1,heights,diff,heights[i][j],vis);
        d = bfs(i,j-1,heights,diff,heights[i][j],vis);
        return a||b||c||d;
        
    }
};