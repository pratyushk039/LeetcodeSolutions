class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& g) {
        vector<int> x(3,0),y(3,0);
        int n = g.size();
        for(int i=n/2 + 1;i<n;i++){y[g[i][n/2]]+=1;g[i][n/2]=-1;}
        
        int r=0,c=0;
        while(r<=n/2){y[g[r][c]]+=1;g[r][c]=-1;r+=1;c+=1;}
        
        r=0;c=n-1;
        
        while(r<n/2){y[g[r][c]]+=1;g[r][c]=-1;r+=1;c-=1;}
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<g[i][j]<<" ";
                if(g[i][j]!=-1){x[g[i][j]]+=1;}
            }
            //cout<<endl;
        }
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<endl;
        //cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        int cost1,cost2,cost3;
        //lets make all y = 0
        cost1 = min(y[1]+y[2]+x[0]+x[2],y[1]+y[2]+x[0]+x[1]);
        cost2 = min(y[0]+y[1]+x[1]+x[2],y[0]+y[1]+x[2]+x[0]);
        cost3 = min(y[0]+y[2]+x[1]+x[0],y[0]+y[2]+x[1]+x[2]);
        return min(min(cost1,cost2),min(cost2,cost3));
    }
};