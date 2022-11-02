class Solution {
public:
    bool valid (string s,string t){
        int a=0;
        for(int i=0;i<8;i++){
            if(s[i]!=t[i]){a+=1;}
        }
        return a==1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size(),eix;
        vector<int> dist(n,INT_MAX),vis(n,0);
        queue<int> q;
        vector<vector<int>> gr(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(valid(bank[i],bank[j])){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(bank[i]==end){eix=i;}
            if(valid(bank[i],start)){
                dist[i]=1;
                q.push(i);
            }
        }
        bool b =false;
        while(!q.empty()){
            int par = q.front();q.pop();
            vis[par]  = 1;
            cout<<bank[par]<<" ";
            if(bank[par]==end){b=true;break;}
            for(int nbrs:gr[par]){
                if(vis[nbrs]==1){continue;}
                dist[nbrs]=min(1+dist[par],dist[nbrs]);
                q.push(nbrs);
            }
        }
        return b?dist[eix]:-1;
    }
};