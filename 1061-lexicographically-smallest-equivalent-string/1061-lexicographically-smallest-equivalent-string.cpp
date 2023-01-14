class Solution {
public:
    vector<char> parent;
    vector<int>rank;
    char find(char x){
        if(parent[x-'a']==x){return x;}
        return parent[x-'a']=find(parent[x-'a']);
    }
    void Union(char x,char y){
        char parX=find(x),parY=find(y);
        if(rank[parX-'a']>rank[parY-'a']){
            parent[parY-'a']=parX;
        }
        else if(rank[parX-'a']<rank[parY-'a']){
            parent[parX-'a']=parY;
        }
        else{
            parent[parY-'a']=parX;
            rank[parX-'a']+=1;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        rank.resize(26,1);
        for(int i=0;i<26;i++){parent[i]='a'+i;}
        int n=s1.size();string ans="";
        for(int i=0;i<n;i++){
            Union(s1[i],s2[i]);
        }
        unordered_map<char,string>map;
        unordered_map<char,char>fin_map;
        for(int i=0;i<26;i++){fin_map['a'+i]='a'+i;}
        for(int i=0;i<26;i++){
            map[find('a'+i)].push_back('a'+i);
        }
        for(auto itr:map){
            char mini='z';
            for(char c:itr.second){mini=min(c,mini);}
            for(char c:itr.second){fin_map[c]=mini;}
        }
        for(char c:baseStr){
            ans.push_back(fin_map[c]);
        }
        return ans;
    }
};