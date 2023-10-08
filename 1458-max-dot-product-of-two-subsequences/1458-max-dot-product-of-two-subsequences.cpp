#define im -1e9
class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        //2. dp[a][b][c] = max of:A[a]*B[b]+ (max dot product considering c-1 from A[a+1:],B[b+1:]),dp[a+1][b],dp[a][b+1]
        //problem is solved even if we don't introduce c.
        //simple lcs.
        int m=A.size(),n=B.size(),l=502;
        vector<vector<int>> dp(l,vector<int>(l,im));
        for(int i=0;i<l;i++){dp[i][n]=0;}
        for(int i=0;i<l;i++){dp[m][i]=0;}
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                dp[i][j] = max(A[i]*B[j]+dp[i+1][j+1],max(dp[i][j+1],dp[i+1][j]));
            }
        }
        //special case : one array is whole positive, other is whole neg.
        if(dp[0][0]==0){
            //cout<<"special";
            sort(A.begin(),A.end());sort(B.begin(),B.end());
            if(A[0]==0 || A[m-1]==0 || B[0]==0 || B[n-1]==0 ){return 0;}
            if(A[0]>B[0]){swap(A,B);swap(m,n);}
            return A[m-1]*B[0];
        }
        return dp[0][0];
        
    }
};