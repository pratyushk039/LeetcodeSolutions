vector<int> ways(9,-1);
vector<int> fact(11,1);
int first=1;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(first==1){
        ways[0]=1;ways[1]=10;ways[2]=91;
        for(int i=1;i<=10;i++){fact[i]=fact[i-1]*i;}
        for(int i=3;i<9;i++){
            int x = 9*9*(fact[8]/fact[10-i]);
            ways[i]=ways[i-1]+x;
        }first=0;}
        return ways[n];
    }
};