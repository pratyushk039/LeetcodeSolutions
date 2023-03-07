class Solution {
public:
    long long minimumTime(vector<int>& time, int ttr) {
        if(time.size()==1){return 1ll*time[0]*ttr;}
        long long lo=1ll,hi=1e12;
        while(lo<hi){
            long long mid = (lo+hi)/2,tr=0ll;
            for(int i=0;i<time.size();i++){
                tr+=1ll*mid/time[i];
                if(tr>=ttr){break;}
            }
            if(tr>=ttr){hi=mid;}
            else{lo=mid+1;}
        }
        return hi;
    }
};