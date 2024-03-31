class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0,y=x;
        while(x){
            sum+=x%10;x/=10;
        }
        return y%sum==0?sum:-1;
    }
};