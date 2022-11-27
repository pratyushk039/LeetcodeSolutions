class Solution {
public:
    int appendCharacters(string s, string t) {
        int m=s.size(),n=t.size(),i=0,j=0;
        while(i<m && j<n){
            if(s[i]==t[j]){j+=1;}
            i+=1;
        }
        
        return n-j;
    }
};