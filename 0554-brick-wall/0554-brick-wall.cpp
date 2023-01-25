class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> m;
        int n=wall.size(),width=0;
        for(int i:wall[0]){width+=i;}
        for(auto vec:wall){
            int j=1,sz=vec.size(),prev=vec[0];m[prev]+=1;
            while(j<sz){m[vec[j]+prev]+=1;prev+=vec[j];j+=1;}
        }
        int ans=INT_MAX;
        for(auto itr:m){
            if(itr.first==0 || itr.first==width){continue;}
            ans=min(ans,n-itr.second);
        }
        if(ans==INT_MAX){return n ;}
        return ans;
    }
};