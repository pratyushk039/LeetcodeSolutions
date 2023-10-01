class Solution {
public:
    string reverseWords(string s) {
        string s1="",temp="";
        for(auto ch:s){
            if(ch==' '){
                reverse(temp.begin(),temp.end());
                s1+=temp;
                s1+=" ";
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        reverse(temp.begin(),temp.end());
        s1+=temp;
        return s1;
    }
};