class Solution {
public:
    int util(long long n){
        if(n==1){
            return 0;
        }
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(n%2==0){
            a = 1+util(n/2);
        }
        else{
            b = 1+util(n-1);
            c = 1+util(n+1);
            b=min(b,c);
        }
        return min(a,b);
    }
    int integerReplacement(int n) {
        return util(1ll*n);
    }
};