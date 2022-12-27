#define v vector
#define pb push_back
class Solution {
public:
    static bool comp(v<int>&a,v<int>&b){
        return a[1]-a[0]<b[1]-b[0];
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        v<v<int>> vec;
        int n = rocks.size();
        for(int i=0;i<n;i++){
            vec.pb({rocks[i],capacity[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        int ans=0;
        for(auto vc:vec){
            int diff = vc[1]-vc[0];
            // cout<<diff<<" "<<k<<endl;
            if(diff<=k){
                ans+=1;
                k-=diff;
            }
            else{break;}
        }
        return ans;
    }
};