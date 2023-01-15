class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int m=queries.size(),r1,r2,c1,c2;
        for(auto vec:queries){
            r1=vec[0],c1=vec[1],r2=vec[2],c2=vec[3];
            for(int i=c1;i<=c2;i++){ans[r1][i]+=1;if(r2<n-1){ans[r2+1][i]-=1;}}
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]+=ans[i-1][j];
            }
        }
        return ans;
    }
};