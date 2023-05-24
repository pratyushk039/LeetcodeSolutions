class Solution {
public:
    //can solve it in root n considering the fact that divisors occur in pairs.
    int kthFactor(int n, int k) {
        bool pfsq=false;
        int i;
        vector<int> factors;
        for(i=1;i*i<=n;i++){
            if(i*i==n){pfsq=true;}
            if(n%i==0){factors.push_back(i);}
        }
        int len = factors.size();
        if(pfsq){len-=1;}
        for(int i=len-1;i>-1;i--){factors.push_back(n/factors[i]);}
        if(factors.size()<k){return -1;}
        return factors[k-1];
    }
};