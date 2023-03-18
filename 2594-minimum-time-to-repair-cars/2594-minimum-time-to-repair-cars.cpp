class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long lo=1ll,hi= 1e18;
        while(lo<hi){
            long long mid=lo+((-lo+hi)/2);
            long long cap=0;
            for(int i=0;i<n;i++){
                cap+= pow(mid/ranks[i],0.5)/1ll;
            }
            if(cap>=cars){hi=mid;}
            else{lo=mid+1;}
        }
        return lo;
    }
};