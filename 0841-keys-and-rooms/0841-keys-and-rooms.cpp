class Solution {
public:
    void dfs(vector<vector<int>>& gr,vector<int> &visited,int curr){
        visited[curr]=1;
        for(int nb:gr[curr]){
            if(visited[nb]==0){
            dfs(gr,visited,nb);}
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        dfs(rooms,visited,0);
        for(int i:visited){
            if(i==0){return false;}
        }
        return true;
    }
};