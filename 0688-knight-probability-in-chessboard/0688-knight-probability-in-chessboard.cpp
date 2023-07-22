class Solution {
public:
    map<pair<pair<int,int>,int>,double> dp;
    double util(int n, int k, int i, int j){
        if(k==0){
            if((i>-1) && (i<n) && (j>-1) && (j<n)){
                return dp[{{i,j},k}]=1.000;
            }
            else{return dp[{{i,j},k}]=0.000;}
        }
        //outta bounds
        if((i<=-1) || (i>=n) || (j<=-1) || (j>=n)){
                return  dp[{{i,j},k}]=0.0000;}
        //
        if(dp.find({{i,j},k})!=dp.end()){return  dp[{{i,j},k}];}
        double a1,a2,a3,a4,a5,a6,a7,a8;
        a1 = util(n,k-1,i-2,j-1);
        a2=  util(n,k-1,i-1,j-2);
        a3 = util(n,k-1,i+1,j-2);
        a4  = util(n,k-1,i+2,j-1);
        a5 = util(n,k-1,i+2,j+1);
        a6 = util(n,k-1,i+1,j+2);
        a7 = util(n,k-1,i-1,j+2);
        a8 = util(n,k-1,i-2,j+1);
        return dp[{{i,j},k}] = (a1+a2+a3+a4+a5+a6+a7+a8)/8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        return util(n,k,row,column);
    }
};