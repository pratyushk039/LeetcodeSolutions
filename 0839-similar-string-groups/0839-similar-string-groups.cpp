class Solution {
public:
    //UnionFind struck me sooo quick XD :)
    vector<int> parent,rank;
    int n;
    int find(int x){
        if(parent[x]==x){return x;}
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int parx=find(x),pary=find(y);
        if(rank[parx]>rank[pary]){
            parent[pary] = parx;
        }
        else if(rank[parx]<rank[pary]){
            parent[parx] = pary;
        }
        else{
            parent[parx]=pary;
            rank[pary]+=1;
        }
    }
    bool check(const string &s3, const string &s4){
        string s1=s3,s2=s4;
        if(s1==s2){return true;}
        int m =s1.size();
        int idx=0;
        vector<int> idc;
        for(int i=0;i<m;i++){
            if(s1[i]!=s2[i]){idx++;idc.push_back(i);}
        }
        if(idx!=2){return false;}
        swap(s1[idc[0]],s1[idc[1]]);
        return s1==s2;
    }
    int numSimilarGroups(vector<string>& strs) {
        this->n = strs.size();
        parent.resize(n);rank.resize(n,0);
        for(int i=0;i<n;i++){parent[i]=i;}
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j])){
                    Union(i,j);
                }
            }
        }
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            set.insert(find(i));
        }
        return set.size();
    }
};