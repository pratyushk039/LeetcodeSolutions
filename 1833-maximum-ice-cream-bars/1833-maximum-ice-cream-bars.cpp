class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size(),i=0,ans=0;
        while(i<n && costs[i]<=coins){
            ans+=1;
            coins-=costs[i];
            i++;
        }
        return ans;
    }
};