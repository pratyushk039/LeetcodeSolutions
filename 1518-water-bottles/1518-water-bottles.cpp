class Solution {
public:
    int numWaterBottles(int fill, int exc) {
        int empty = 0,drank=0;;
        while(fill>0){
            drank+=fill;
            empty+=fill;
            fill = empty/exc;
            empty = empty%exc;
        }
        return drank;
    }
};