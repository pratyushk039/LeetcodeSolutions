class Solution {
public:
    bool util(vector<vector<char>> & board,string word,int wstart,int rstart,int cstart,vector<vector<int>> &vis){
        int m = board.size(),n=board[0].size();
        vis[rstart][cstart]=1;
        if(wstart==word.size()-1){return true;}
        bool l=false,r=false,u=false,d=false;
        //d
        if(rstart+1<m){
            if(vis[rstart+1][cstart]==0 && board[rstart+1][cstart]==word[wstart+1]){
                d=util(board,word,wstart+1,rstart+1,cstart,vis);
            }
        }
        //u
        if(rstart-1>-1){
            if(vis[rstart-1][cstart]==0 && board[rstart-1][cstart]==word[wstart+1]){
                u=util(board,word,wstart+1,rstart-1,cstart,vis);
            }
        }
        //l
        if(cstart-1>-1){
            if(vis[rstart][cstart-1]==0 && board[rstart][cstart-1]==word[wstart+1]){
                l=util(board,word,wstart+1,rstart,cstart-1,vis);
            }
        }
        //r
        if(cstart+1<n){
            if(vis[rstart][cstart+1]==0 && board[rstart][cstart+1]==word[wstart+1]){
                r=util(board,word,wstart+1,rstart,cstart+1,vis);
            }
        }
        vis[rstart][cstart]=0;
        return (l || r || u || d);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool x = util(board,word,0,i,j,vis);
                    if(x){return true;}
                }
            }
        }
        return false;
    }
};