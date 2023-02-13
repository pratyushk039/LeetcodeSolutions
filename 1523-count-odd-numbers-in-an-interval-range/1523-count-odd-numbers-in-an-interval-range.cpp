class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0){low+=1;}
        if(high%2==0){high-=1;}
        int n=high-low+1;
        return (n+1)/2;
    }
};