#define piv pair<double,vector<int>>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int exs) {
        int n = classes.size();
        double ans=0.0;
        priority_queue<piv> pq;
        for(auto v:classes){
            pq.push({1.0*(v[0]+1)/(v[1]+1) - 1.0*v[0]/v[1],v});
            ans+=1.0*v[0]/v[1];
        }
        while(exs>0){
            auto pdv = pq.top();pq.pop();
            ans+=pdv.first;
            pq.push(
                {1.0*(pdv.second[0]+2)/(pdv.second[1]+2) - 1.0*(pdv.second[0]+1)/(pdv.second[1]+1),
                 {pdv.second[0]+1,pdv.second[1]+1}}
            );
            exs-=1;
        }
        return ans/n;
    }
};
#undef piv