class Solution {
public:
    int toNum(string s){
        int p=0;
        int n=s.size();
        reverse(s.begin(),s.end());
        unordered_map<char,int> map;map['0']=0;map['1']=1;
        for(int i=0;i<n;i++){
            p+=map[s[i]]*pow(2,i);
        }
        return p;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        int qsize=q.size(),n=s.size();
        unordered_map<int,vector<int>> map;
        vector<vector<int>> ans(q.size());
        for(int size=1;size<=min(30,n);size++){
            for(int i=0;i<=n-size;i++){
                int subs = toNum(s.substr(i,size));
                if(map.find(subs)==map.end()){map[subs]={i,i+size-1};}
                //cout<<subs<<" -> "<<map[subs][0]<<" "<<map[subs][1]<<endl;
                
            }
        }
        for(auto itr:map){
            int x = itr.first;
            auto v = map[itr.first];
            //cout<<x<<" ";
        }
        for(int i=0;i<qsize;i++){
            int z1=q[i][0],z2=q[i][1];
            int val = ((z1)^(z2));
            //cout<<map[val][0]<<" "<<map[val][1]<<endl;
            if(map.find(val)!=map.end()){ans[i]=map[val];}
            else{ans[i]={-1,-1};}
        }
        return ans;
    }
};