#define vi vector<int>
class Solution {
public:
    bool exists(int mid,vi &p,int k){
        int count=1,prev=p[0];
        for(int i=1;i<p.size();i++){
            if(p[i]>=mid+prev){
                prev=p[i];
                count+=1;
                if(count==k){return true;}
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(),prices.end());
        int l=0,r=1e9,ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(exists(mid,prices,k)){l=mid+1;ans=mid;}
            else{r=mid-1;}
        }
        return ans;
    }
};