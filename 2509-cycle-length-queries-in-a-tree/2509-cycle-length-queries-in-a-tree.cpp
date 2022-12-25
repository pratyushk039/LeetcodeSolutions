class Solution {
public:
    int height(int node){
        //height h has nodes numbered from 2**(h-1) to 2**h - 1.
        //i.e. h = most significant set bit's position,1-based indexing.
        int h;
        for(int i=31;i>0;i--){
            if((node&(1<<i))!=0){h=i;break;}
        }
        return h;
    }
    int lca(int x,int y){
        if(height(y)>height(x)){
            swap(x,y);
        }
        int p = height(x)-height(y);
        x=x/pow(2,p);
        while(x!=y){
            x=x/2;
            y=y/2;
        }
        return x;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        int m = q.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int a = q[i][0],b = q[i][1];
            ans[i] = height(a)+height(b)-2*height(lca(a,b))+1;
        }
        return ans;
    }
};