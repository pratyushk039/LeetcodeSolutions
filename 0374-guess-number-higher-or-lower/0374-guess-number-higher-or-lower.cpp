/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int util(int start,int end){
        long long mid = (1ll*start+end)/2;
        if(guess(mid)==0){return mid;}
        else if(guess(mid)==-1){return util(start,mid-1);}
        else{return util(mid+1,end);}
    }
    int guessNumber(int n) {
        return util(1,n);
    }
};