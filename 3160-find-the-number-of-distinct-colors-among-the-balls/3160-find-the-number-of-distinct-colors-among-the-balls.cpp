class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> ctb;
        unordered_map<int,int> btc;
        
        int n = queries.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int ball=queries[i][0],color = queries[i][1];
            // the ball was painted previously
            if(btc.find(ball)!=btc.end() && ctb[btc[ball]].find(ball)!=ctb[btc[ball]].end()){
                ctb[btc[ball]].erase(ball);
                if(ctb[btc[ball]].size()==0){ctb.erase(btc[ball]);}
            }
            btc[ball] = color;
            ctb[color].insert(ball);
            ans[i] = ctb.size();
        }
        return ans;
        
    }
};