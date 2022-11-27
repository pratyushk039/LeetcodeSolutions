class Solution {
public:
    int pivotInteger(int n) {
        int s = n*(n+1)/2;
        double ans = pow(s,0.5);
        if(floor(ans)==ans){return (int)ans;}
        return -1;
    }
};