class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1=0,xor2=0,pos;
        for(int i:nums){
            xor1=(xor1^i);
        }
        for(int i =0;i<32;i++){
            if(((xor1) & (1<<i))!=0){
                pos=i;
                break;
            }
        }
        for(int i:nums){
            if((i&(1<<pos))!=0){xor2=xor2^i;}
        }
        int xor3=xor1^xor2;
        return {xor2,xor3};
    }
};