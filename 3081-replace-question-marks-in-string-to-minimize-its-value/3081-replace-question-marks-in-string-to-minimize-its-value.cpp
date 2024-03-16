class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        unordered_map<char,int>map;
        for(auto c='a';c<='z';c++){map[c]=0;}
        for(auto c:s){
            if(c=='?')continue;
            map[c]+=1;
            
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='?'){ans+=s[i];continue;}
            int min=INT_MAX;
            char minc = 'a';
            for(auto c='a';c<='z';c++){if(min>map[c]){minc=c;min=map[c];}}
            map[minc]+=1;
            //cout<<map[minc]<<endl;
            ans+=minc;
        }
        string k1="";
    
        for(int i=0;i<n;i++){
            if(s[i]=='?'){k1+=ans[i];}
        }
        sort(k1.begin(),k1.end());
        
        int j=0;
        string ans2="";
        for(int i=0;i<n;i++){
            if(s[i]!='?'){ans2+=ans[i];continue;}
            ans2+=k1[j];j++;
            
        }
        
        return ans2;
    }
};