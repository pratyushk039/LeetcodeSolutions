class Solution {
public:
    int ans;
    vector<int> s;
    vector<string> w;
    void util(int idx,vector<int>&freq,int score){
        int n = w.size(),_score=score;
        if(idx==n){ans=max(ans,score);return;}
        
        bool all_positive=true;
        vector<int> f = freq;
        for(auto c: w[idx]){
            freq[c-'a']-=1;
            _score+=s[c-'a'];
            if(freq[c-'a']<0){all_positive=false;break;}
        }
        if(all_positive){
            util(idx+1,freq,_score);
        }
        freq=f;
        util(idx+1,freq,score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        ans=0;
        for(auto c:letters){freq[c-'a']+=1;}
        s=score;
        w=words;
        util(0,freq,0);
        return ans;
    }
};