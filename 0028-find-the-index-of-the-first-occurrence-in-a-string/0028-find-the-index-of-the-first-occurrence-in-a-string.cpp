class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(),k = needle.size();
        //auto ptr = haystack.begin();
        if(k>n){return -1;}
        for(int i=0;i<=n-k;i++){
            if(needle == haystack.substr(i,k)){return i;}
        }
        return -1;
    }
};