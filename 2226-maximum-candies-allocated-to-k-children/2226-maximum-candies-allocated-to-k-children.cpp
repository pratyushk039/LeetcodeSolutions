class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lo=0,hi=1e7,n=candies.size();
        while(lo<hi){
            long long mid=(lo+hi+1)/2;
            long long num=0;
            for(int i=0;i<n;i++){num+=1ll*(candies[i]/mid);}
            if(num>=k){lo=mid;}
            else{hi=mid-1;}
        }
        return hi;
    }
};