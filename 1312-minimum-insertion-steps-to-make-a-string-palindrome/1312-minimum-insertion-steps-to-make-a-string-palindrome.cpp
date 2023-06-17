class Solution {
public:
    vector<vector<int>> dp;
    int util(string &s, int i, int j){
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(i==j){return dp[i][j]=0;}
        if(s[i]==s[j]){return dp[i][j]=util(s,i+1,j-1);}
        else{
            return dp[i][j] = 1+min(util(s,i+1,j),util(s,i,j-1)); 
        }
        return 0;
    }
    int minInsertions(string &s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return util(s,0,n-1);
    }
};