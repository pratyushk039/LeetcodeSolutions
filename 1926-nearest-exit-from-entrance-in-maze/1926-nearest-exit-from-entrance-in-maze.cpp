class Solution {
public:
    int m,n;
    bool exit(int i, int j){
        return (i==m-1)||(i==0)||(j==n-1)||(j==0);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto p = q.front();q.pop();
            int r = p.first, c = p.second;
            if(exit(r,c) && !(r==entrance[0] && c == entrance[1])){return dist[r][c];}
            if(r+1<m && maze[r+1][c]!='+' && vis[r+1][c]==0){
                dist[r+1][c]=1+dist[r][c];
                q.push({r+1,c});
                vis[r+1][c]=1;
            }
            if(r-1>-1 && maze[r-1][c]!='+' && vis[r-1][c]==0){
                dist[r-1][c]=1+dist[r][c];
                q.push({r-1,c});
                vis[r-1][c]=1;
            }
            if(c+1<n && maze[r][c+1]!='+' && vis[r][c+1]==0){
                dist[r][c+1]=1+dist[r][c];
                q.push({r,c+1});
                vis[r][c+1]=1;
            }
            if(c-1>-1 && maze[r][c-1]!='+' && vis[r][c-1]==0){
                dist[r][c-1]=1+dist[r][c];
                q.push({r,c-1});
                vis[r][c-1]=1;
            }
            
        }
        return -1;
    }
};