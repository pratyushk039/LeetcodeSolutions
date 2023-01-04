bool k =true;
vector<int> dp(1e5+1,0);
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if(k){
            k=false;
            dp[1]=INT_MAX;
            dp[2]=1;dp[3]=1;
            for(int i=4;i<=1e5;i++){
                if(dp[i-3]==INT_MAX && dp[i-2]==INT_MAX){dp[i]=INT_MAX;}
                else{
                    dp[i] = 1+min(dp[i-3],dp[i-2]);
                }
            }
        }
        unordered_map<int,int>um;
        for(int i:tasks){
            um[i]+=1;
        }
        int ans=0;
        for(auto itr:um){
            if(dp[itr.second]==INT_MAX){return -1;}
            ans+=dp[itr.second];
        }
        return ans;
    }
};