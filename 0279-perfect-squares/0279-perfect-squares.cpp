class Solution {
public:
    int root(int n){
    int ans;
    for(int i=1;i*i<=n;i++){
        ans=i;
    }
    return ans;
}
    int numSquares(int n) {
        if(n==1) return 1;
    vector<int> ways(n+1,0);
    ways[1]=1;
    for(int i=2;i<n+1;i++){
        int k = root(i);
        int mini=INT_MAX;
        for(int j=1;j<=k;j++){
            mini = min(ways[i-j*j],mini);
        }
        ways[i]=1+mini;
    }
    return ways[n];
    }
};