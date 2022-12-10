#define pq priority_queue
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(k==0 || edges.size()==0){return *max_element(vals.begin(),vals.end());}
        unordered_map<int,pq<int>> m;
        for(auto v:edges){
            m[v[0]].push(vals[v[1]]);
            m[v[1]].push(vals[v[0]]);
        }
        int ans = -INT_MAX;
        for(auto itr:m){
            int vx  = itr.first;
            int x = vals[vx],y=x;
            ans=max(ans,y);
            int i=0;
            while(i<k && !m[vx].empty()){
                i+=1;
                x+=m[vx].top();
                m[vx].pop();
                ans=max(ans,x);
            }
        }
        return ans;
    }
};