
class Solution {
public:
    bool util(int x,vector<vector<char>>& board){
        unordered_map<char,int> umap1;
        //row
        for(int i=0;i<9;i++){
            if(board[x][i]=='3' && x==1){cout<<"true"<<" ";}
            if(board[x][i]=='.'){continue;} 
            if(umap1.find(board[x][i])==umap1.end()){
                umap1[board[x][i]]=1;
            }
             else if(umap1.find(board[x][i])!=umap1.end()){
                return false;
            }
        }
        //col
        unordered_map<char,int> umap2;
        for(int i=0;i<9;i++){
            if(board[i][x]=='.'){continue;} 
            if(umap2.find(board[i][x])==umap2.end()){
                umap2[board[i][x]]=1;
            }
            else if(umap2.find(board[i][x])!=umap2.end()){
                return false;
            }
        }
        //subgrid
        unordered_map<char,int> umap3;
        int st;
        if(x>=0 && x<=2){st=0;}
        else if(x>=3 && x<=5){st=3;}
        else if(x>=6 && x<=8){st=6;}
        for(int r=st;r<st+3;r++){
            for(int c=st;c<st+3;c++){
                if(board[r][c]=='.'){continue;} 
                if(umap3.find(board[r][c])==umap3.end()){
                    umap3[board[r][c]]=1;
                }
                 else if(umap3.find(board[r][c])!=umap3.end()){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> v = {{3,0},{6,0},{6,3},{0,3},{0,6},{3,6}};
        for(auto p:v){
            unordered_map<char,int> umap3;
            for(int r=p.first;r<p.first+3;r++){
            for(int c=p.second;c<p.second+3;c++){
                if(board[r][c]=='.'){continue;} 
                if(umap3.find(board[r][c])==umap3.end()){
                    umap3[board[r][c]]=1;
                }
                 else if(umap3.find(board[r][c])!=umap3.end()){
                    return false;
                }
            }
        }
        }
        for(int i=0;i<9;i++){
            if(!util(i,board)){return false;}
        }
        return true;
    }
};