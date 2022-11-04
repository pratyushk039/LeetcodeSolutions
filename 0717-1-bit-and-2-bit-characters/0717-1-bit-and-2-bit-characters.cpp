class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(),i=0;
        while(i<n){
            if(bits[i]==1){
                if(i==n-2){return false;}
                i+=2;
            }
            else{
                if(i==n-1){return true;}
                i+=1;
            }
        }
        return true;
    }
};