#define um unordered_map<char,int>
class Solution {
public:
    bool comp(string &s1,string &s2,um& map){
        int m=s1.size(),n=s2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(s1[i]!=s2[j]){
                return map[s1[i]]<map[s2[j]];
            }
            i+=1;j+=1;
        }
        return s1.size()<=s2.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        um map;
        int i=0;
        for(char c:order){
            map[c]=i;
            i+=1;
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!comp(words[i],words[j],map)){return false;}
            }
        }
        return true;
    }
};