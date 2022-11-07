class Solution {
public:
    int countSubstrings(string s, string t) {
        unordered_map<string,int> tsubs;
        vector<string> ssubs;
        int n =s.size(),m=t.size();
        for(int i=0;i<m;i++){
            for(int l=1;l<m-i+1;l++){tsubs[t.substr(i,l)]+=1;}
        }
        for(int i=0;i<n;i++){
            for(int l=1;l<n-i+1;l++){ssubs.push_back(s.substr(i,l));}
        }
        int ans = 0;
        //for(auto &words:tsubs){cout<<words<<" ";}
        for(auto word:ssubs){
            for(int i=0;i<word.size();i++){
                char c = word[i];
                vector<int> alpha(26,0);
                alpha[c-'a']=1;
                for(int j=0;j<26;j++){
                    if(alpha[j]==0){
                        word[i]=(char)('a'+j);//cout<<word<<" ";
                        if(tsubs.find(word)!=tsubs.end()){ans+=tsubs[word];}
                    }
                }
                word[i]=c;
            }
        }
        return ans;
    }
};