#define pb push_back
vector<long long> vec(1001,-1);
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        if(vec[n]!=-1){return vec[n]%mod;}
        vec[0] = 0;
        vec[1]=1;
        vec[2]=2;
        vec[3] = 5;
        for(int i=4;i<=1000;i++){
            vec[i] = 2*vec[i-1]%mod+vec[i-3]%mod;
        }
        return vec[n]%mod;
    }
};