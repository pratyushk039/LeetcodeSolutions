class Solution {
public:
    int lis(vector<int> &v){
        int n = v.size(),ans=0;
        vector<int> dp(n,0);
        for(int i =1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j]){
                    dp[i]+=1;
                    ans+=dp[j];
                }
            }
        }
        return ans;
    }
    int numTeams(vector<int>& rating) {
        int a1=lis(rating);
        reverse(rating.begin(),rating.end());
        int a2 = lis(rating);
        //cout<<a1<<" "<<a2;
        return a1+a2;
    }
};