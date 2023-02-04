class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        int n=p.size();
        unordered_map<int,int> prize;
        for(int i:p){
            if(prize.find(i)!=prize.end()){continue;}
            prize[i] = upper_bound(p.begin(),p.end(),i+k)-lower_bound(p.begin(),p.end(),i);
        }
        
        vector<int> sufmax(n,prize[p[n-1]]);
        for(int i=n-2;i>-1;i--){
            sufmax[i]=max(sufmax[i+1],prize[p[i]]);
            //cout<<sufmax[i+1]<<endl;
        }
        
        int ans=-INT_MAX;
        for(int i=0;i<n;i++){
            int idx = upper_bound(p.begin(),p.end(),p[i]+k)-p.begin();
            int maxima;
            if(idx>n-1){maxima=0;}else{maxima = sufmax[idx];}
            ans=max(ans,maxima+prize[p[i]]);
        }
        return ans;
    }
};