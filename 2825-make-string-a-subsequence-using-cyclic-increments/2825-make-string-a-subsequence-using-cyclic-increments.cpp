class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n = s1.size(),m = s2.size(),i=0,j=0;
        while((i<n) && (j<m)){
            char c1 = s2[j],c2 = 'a' + (s2[j]-'a'+25)%26;
            if((s1[i]==c1) || (s1[i]==c2)){i++;j++;}
            else{i++;}
        }
        
        return j==m;
    }
};