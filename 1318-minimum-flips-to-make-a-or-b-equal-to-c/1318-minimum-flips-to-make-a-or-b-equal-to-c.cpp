class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<31;i++){
            int mask = (1<<i);
            int a_bit = ((mask)&(a))==0?0:1;
            int b_bit = ((mask)&(b))==0?0:1;
            int c_bit = ((mask)&(c))==0?0:1;
            if((a_bit|b_bit)!=c_bit){
                if(c_bit == 1){
                    ans+=1;
                }
                else{
                    ans+=a_bit+b_bit;
                }
            }
        }
        return ans;
    }
};