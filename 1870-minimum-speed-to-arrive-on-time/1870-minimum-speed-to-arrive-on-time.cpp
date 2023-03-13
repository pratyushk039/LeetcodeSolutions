class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(),lo=1,hi=1e9;
        while(lo<hi){
            int mid=(lo+hi)/2;
            double time=0.00;
            for(int i=0;i<n;i++){
                time+= (i!=n-1)?1.0*ceil(1.0*dist[i]/mid):1.0*dist[i]/mid;
            }
            if(time<=hour){hi=mid;}
            else{lo=mid+1;}
        }
        return lo==1e9?-1:lo;
    }
};