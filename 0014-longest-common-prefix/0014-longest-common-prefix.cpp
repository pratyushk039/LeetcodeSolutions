class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        bool b = false;
        int n = INT_MAX;
        for(string c:strs){n= n>c.size()?c.size():n;}
        for(int i=0;i<n;i++){
            char c = strs[0][i];
            b=false;
            for(auto word:strs){
                if(word[i]!=c){b=true;break;}
            }
            if(b){break;}
            s.push_back(c);
        }
        return s;
    }
};