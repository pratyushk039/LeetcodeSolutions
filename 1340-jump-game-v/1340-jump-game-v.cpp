class Solution {
public:
    vector<int> arr,dp;
    int d;
    int util(int idx){
        if(dp[idx]!=-1){return dp[idx];}
        int n = arr.size(),ans=1;
        int l_l = max(0,idx-d),r_l=min(n-1,idx+d);
        for(int i=idx+1;i<=r_l;i++){
            if(arr[i]>=arr[idx]){break;}
            else{
                ans=max(ans,1+util(i));
            }
        }
        for(int i=idx-1;i>=l_l;i--){
            if(arr[i]>=arr[idx]){break;}
            else{
                ans=max(ans,1+util(i));
            }
        }
        return dp[idx]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        this->arr=arr;
        this->d=d;
        int n = arr.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            util(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};