class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> ded; for(auto x:deadends){ded.insert(x);}
        //edgecases
        if(ded.find("0000")!=ded.end()){return -1;}
        //
        unordered_map<string,pair<int,int>> vsdt;
        q.push("0000");
        vsdt["0000"]={1,0};
        while(!q.empty()){
            string par = q.front();q.pop();
            if(par==target){return vsdt[par].second;}
            for(int i=0;i<4;i++){
                string nbr1 = par,nbr2=par;
                if(par[i]=='9'){nbr1[i]='0';}
                else{nbr1[i]=par[i]+1;}
                if((ded.find(nbr1)==ded.end()) && (vsdt.find(nbr1)==vsdt.end())){
                    vsdt[nbr1].first=1;vsdt[nbr1].second = vsdt[par].second+1;
                    q.push(nbr1);
                    if(nbr1==target){return vsdt[nbr1].second;}
                }
                if(par[i]=='0'){nbr2[i]='9';}
                else{nbr2[i]=par[i]-1;}
                if((ded.find(nbr2)==ded.end()) && (vsdt.find(nbr2)==vsdt.end())){
                    vsdt[nbr2].first=1;vsdt[nbr2].second = vsdt[par].second+1;
                    q.push(nbr2);
                    if(nbr2==target){return vsdt[nbr2].second;}
                }
            }
        }
        return -1;
    }
};