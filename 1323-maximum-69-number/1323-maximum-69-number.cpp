class Solution {
public:
    int maximum69Number (int num) {
        int sx=-1,ni=-1;
        int x = num;
        while(x>0){
            if(x%10==6){sx++;ni=sx;x/=10;continue;}
            sx++;x/=10;
        }
        if(ni!=-1){
            num+=3*pow(10,ni);
        }
        return num;
    }
};