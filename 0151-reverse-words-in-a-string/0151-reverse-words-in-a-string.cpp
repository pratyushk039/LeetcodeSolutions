class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string temp="";
        vector<string> arr;
        for(auto ch:s){
            if(ch==' '){
                if(temp=="" || temp==" "){continue;}
                arr.push_back(temp);
                temp="";
            }
            else{
                //cout<<ch<<endl;
                temp+=ch;
            }
        }
        string ans = arr[arr.size()-1];
        for(int i=arr.size()-2;i>-1;i--){
            ans+=' '+arr[i];
        }
        return ans;
    }
};