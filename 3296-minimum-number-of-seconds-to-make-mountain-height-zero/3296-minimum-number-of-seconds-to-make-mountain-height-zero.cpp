class Solution {
public:
    long long minNumberOfSeconds(int mh, vector<int>& workerTimes) {
        long long ans,hi=1e18*1ll,lo=1;
        while(hi>=lo){
            long long mid = lo+(hi-lo)/2,h=0;
            for(auto t : workerTimes){
                double c = 1.0*mid/t;
                h+=max(0,int(sqrt(8*c+1)-1)/2);
            }
            // cout<<h<<" "<<mid<<endl;
            if(h>=mh){ans=mid;hi=mid-1;}
            else{lo=mid+1;}
        }
        return ans;
    }
};