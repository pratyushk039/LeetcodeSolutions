class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==1){return ceil(1.0*piles[0]/h);}
        int lo=1,hi=1e9;
        while(lo<hi){
            int mid = (lo+hi)/2,tr=0;
            for(int i=0;i<piles.size();i++){
                tr+=ceil(1.0*piles[i]/mid);
                if(tr>h){break;}
            }
            if(tr<=h){hi=mid;}
            else{lo=mid+1;}
        }
        return hi;
    }
};