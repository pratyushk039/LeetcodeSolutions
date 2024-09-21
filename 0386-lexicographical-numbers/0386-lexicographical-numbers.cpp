class Solution {
public:
    vector<int> ans;
    void dfs(int x, int n){
        for(int k = 0;k<10;k++){
            if(10*x+k<=n){ans.push_back(10*x+k);dfs(10*x+k,n);}
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<10;i++){
            if(i<=n){ans.push_back(i);
            dfs(i,n);}
        }
        return ans;
    }
};