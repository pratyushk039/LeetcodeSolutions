class Solution {
public:
    long long calcSum(int m, int len){
        int k = max(m-1-len,0);
        if(len>=m-1){
            int k = len-m+1;
            return 1ll*m*(m-1)/2 + 1ll*k;
        }
        else{
            int k = m-1-len;
            return 1ll*m*(m-1)/2 - 1ll*k*(k+1)/2;
        }
    }
    int maxValue(int n, int idx, int maxSum) {
        int hi = INT_MAX,lo=1,l_len=idx,r_len=n-1-idx;
        long long l_sum =0*1ll,r_sum=0*1ll,sum=0*1ll;
        while(hi>lo){
            int m = lo + (hi-lo)/2;
            l_sum = calcSum(m,l_len);
            r_sum = calcSum(m,r_len);
            sum = m+l_sum+r_sum;
            if(sum==1ll*maxSum){
                return m;
            }
            else if(sum<1ll*maxSum){
                lo=m+1;
            }
            else{
                hi=m;
            }
        }
        return lo-1;
    }
};