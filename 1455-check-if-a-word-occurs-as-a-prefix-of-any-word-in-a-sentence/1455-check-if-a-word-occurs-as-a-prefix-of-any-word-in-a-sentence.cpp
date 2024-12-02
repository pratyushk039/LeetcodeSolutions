class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence+=" ";
        string s = "";
        int idx=1;
        for(auto c:sentence){
            if(c==' '){if(s.size()>=searchWord.size() && s.substr(0,searchWord.size())==searchWord){return idx;}else{s="";idx+=1;continue;}}
            s+=c;
        }
        return -1;
    }
};