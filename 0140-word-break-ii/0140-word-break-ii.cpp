#define v vector
class Solution {
public:
    v<string> ans;
    void util(int idx, unordered_set<string> &words, string st, string &s){
        int n = s.size();
        if(idx==n){if(st.size()>1){st=st.substr(1);};ans.push_back(st);return;}
        string word = "";
        for(int i=idx;i<n;i++){
            word+=s[i];
            if(words.find(word)!=words.end()){
                util(i+1,words,st+" "+word,s);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto w:wordDict){
            words.insert(w);
        }
        util(0,words,"",s);
        return ans;
    }
};