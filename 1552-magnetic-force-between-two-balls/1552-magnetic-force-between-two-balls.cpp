class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        int lo=1,hi=1e9,n=p.size();
        sort(p.begin(),p.end());
        while(lo<hi){
            int balls=1,mid=(lo+hi+1)/2,prev=p[0];
            for(int i=1;i<n;i++){
                if(p[i]>=prev+mid){prev=p[i];balls+=1;}
            }
            if(balls>=m){lo=mid;}
            else{hi=mid-1;}
        }
        return lo;
    }
};