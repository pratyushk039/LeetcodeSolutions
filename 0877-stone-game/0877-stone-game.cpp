class Solution {
public:
    int util(bool alice,vector<vector<int>>&dp,int start, int end,vector<int>& piles,int suma,int sumb){
        if(dp[start][end]!=-1){return dp[start][end];}
        if(start==end){bool x = alice?suma+piles[start]>sumb:suma>sumb+piles[start];
                      if(x)return dp[start][end]=1;else return dp[start][end]=0;}
        if(alice){
            int x = util(!alice,dp,start+1,end,piles,suma+piles[start],sumb)+util(!alice,dp,start,end-1,piles,suma+piles[end],sumb);
            return x>0?dp[start][end]=1:dp[start][end]=0;
        }
        else{
            int x = util(!alice,dp,start+1,end,piles,suma,sumb+piles[start])+util(!alice,dp,start,end-1,piles,suma,sumb+piles[end]);
            return x>0?dp[start][end]=1:dp[start][end]=0;
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int x = util(true,dp,0,n-1,piles,0,0);
        return x>0;
    }
};