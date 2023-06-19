#define v vector
#define ll long long
class Solution {
public:
    v<v<v<ll>>> dp;
    v<v<int>> dp2;
    int row,col;
    v<string> grid;
    ll util(int r,int c, int k){
        if(dp2[r][c]==0){return dp[r][c][k]=0;} //no way to cut further.
        if(k==0){return dp[r][c][k]=dp2[r][c];}
        if(dp[r][c][k]!=-1){
            return dp[r][c][k];
        }
        ll s=0*1ll;
        int f_r=r,f_c=c;
        //just need to optimise this part using another dp.--------------//
        bool found=false;
        for(int i=r;i<row;i++){
            for(int j=c;j<col;j++){
                if(grid[i][j]=='A'){
                    f_r=i;found=true;break;
                }
            }
            if(found){break;}
        }
        
        found=false;
        for(int j=c;j<col;j++){
            for(int i=r;i<row;i++){
                if(grid[i][j]=='A'){
                    f_c=j;found=true;break;
                }
            }
            if(found){break;}
        }
        //--------------------//--------------------//--------------------//
        
        //for rows
        for(int i=f_r+1;i<row;i++){
            s+=util(i,c,k-1);
        }
        //for cols
        for(int i=f_c+1;i<col;i++){
            s+=util(r,i,k-1);
        }
        return dp[r][c][k]=s;
    }
    int ways(vector<string>& pizza, int pieces) {
        row = pizza.size(),col=pizza[0].size();
        int mod=1e9+7;
        dp.resize(51,v<v<ll>>(51,v<ll>(11,-1)));
        dp2.resize(row,v<int>(col,0));
        grid=pizza;
        for(int i=row-1;i>-1;i--){
            for(int j=col-1;j>-1;j--){
                if(pizza[i][j]=='A'){dp2[i][j]=1;continue;}
                int a=0,b=0,c=0;
                if(j+1<col){a=dp2[i][j+1];}
                if(i+1<row){b=dp2[i+1][j];}
                if((j+1<col) && (i+1<row)){c=dp2[i+1][j+1];}
                dp2[i][j]=(a||b||c);
            }
        }
        ll ans = util(0,0,pieces-1);
        
        return ans%mod;
    }
};