class TreeAncestor {
public:
    int n,m;
    vector<vector<int>> Par;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        m=30;
        Par.resize(n,vector<int>(m,-1));
        TableDP(parent);
        
    }
    void TableDP(vector<int>& par_gr){
        for(int i=0;i<n;i++){Par[i][0] = par_gr[i];}
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int x =Par[i][j-1];
                Par[i][j] = x==-1?-1:Par[x][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<30;i++){
            int bitmask = (1<<i);
            if(k&bitmask){node=Par[node][i];if(node==-1){return -1;}}
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */