class Solution {
public:
    int n;
    vector<int> numConv(int x){
        int r,c;
        for(int i=1;i<=n;i++){
            if(x<=i*n && x>(i-1)*n){
                r=i-1;
                break;
            }
        }
        if(r%2==0){
            //l to r
            c=x-(r*n+1);
        }
        else{
            c= n-(x-(r*n+1))-1;
        }
        return {n-1-r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<int> vis(n*n+1,0);
        vector<int> dist(n*n+1,INT_MAX);
        queue<int> q;
        if(board[n-1][0]==-1){q.push(1);vis[1]=1;}
        else {q.push(board[n-1][0]);vis[board[n-1][0]]=1;}
        dist[1]=0;
        while(!q.empty()){
            int curr = q.front();q.pop();
            if(curr==n*n){break;}
            for(int i=curr+1;i<=min(curr + 6, n*n);i++){
                vector<int>vc=numConv(i);int r1=vc[0],c1=vc[1];
                int nbr = board[r1][c1]==-1?i:board[r1][c1];
                if(vis[nbr]==0){
                    dist[nbr]=1+dist[curr];
                    q.push(nbr);
                    vis[nbr]=1;
                }
            }
        }
        return dist[n*n]==INT_MAX?-1:dist[n*n];
    }
};