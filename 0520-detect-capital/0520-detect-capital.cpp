class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(),cap=0;
        for(char ch:word){
            if(ch<='Z' && ch>='A'){cap+=1;}
        }
        if(((cap==1)&&(word[0]<='Z')&&(word[0]>='A')) || (cap==0) || (cap==n)){
            return true;
        }
        return false;
    }
};