#define vvi vector<vector<int>>
#define vi vector<int>
class Comp{
    public:
    bool operator()(vi &a,vi &b){
        if(a[1]==b[1]){
            return a[2]>b[2];
        }
        return a[1]>b[1];
    }
};
class Solution {
public:
    static bool comp(vi &a,vi &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vi,vvi,Comp> pq;
        vi ans;
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end(),comp);
        //for(auto vec:tasks){cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;}
        int n = tasks.size(),idx=1;
        pq.push(tasks[0]);
        long long time  = 1ll*tasks[0][0];
        while(!pq.empty()){
            vi tsk = pq.top();pq.pop();
            ans.push_back(tsk[2]);
            time+=tsk[1];
            while(idx<n){
                if(tasks[idx][0]<=time){pq.push(tasks[idx]);idx+=1;}
                else{break;}
            }
            if(pq.empty() && idx<n){pq.push(tasks[idx]);time=1ll*tasks[idx][0];idx+=1;}
        }
        return ans;
    }
};