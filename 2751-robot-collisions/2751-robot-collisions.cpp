class Solution {
public:
    //stack,greedy
    static bool comp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    static bool comp2(vector<int>&a, vector<int>&b){
        return a[3]<b[3];
    }
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hts, string drs) {
        //L=-1,R=1; --> Right is the positive direction.
        int n = pos.size();
        vector<vector<int>> sck(n,vector<int>(4,-1));
        for(int i=0;i<n;i++){
            sck[i][0]=pos[i];
            sck[i][1]=hts[i];
            sck[i][2]= (drs[i]=='L'?-1:1);
            sck[i][3]=i; // original index.
        }
        sort(sck.begin(),sck.end(),comp);
        stack<vector<int>> s;
        for(int i=0;i<n;i++){
            if(s.size()==0){s.push(sck[i]);continue;}
            
            auto prev = s.top();
            auto curr = sck[i];
            if(curr[2]==-1 && prev[2]==1){
                vector<int> temp(4);
                bool b = false;
                while(curr[2]==-1 && prev[2]==1){
                    s.pop();
                    if(curr[1]==prev[1]){b=true;break;}
                    if(curr[1]>prev[1]){temp = {curr[0],curr[1]-1,-1,curr[3]};}
                    else{temp = {prev[0],prev[1]-1,1,prev[3]};}
                    curr=temp;
                    if(s.size()>0)prev = s.top();
                    else break;
                }
                if(!b)s.push(curr);
            }
            else{
                s.push(curr);
            }
        }
        vector<vector<int>> ans1;
        vector<int> ans;
        while(!s.empty()){
            auto temp = s.top();s.pop();
            ans1.push_back(temp);
        }
        sort(ans1.begin(),ans1.end(),comp2);
        for(auto k:ans1){ans.push_back(k[1]);}
        return ans;
    }
};