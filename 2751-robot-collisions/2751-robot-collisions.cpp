class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hts, string dts) {
        int n = pos.size();
        vector<vector<int>> arr(n);
        stack<vector<int>> s;
        
        for(int i=0;i<n;i++){
            int x ;
            if(dts[i]=='L')x=0;
            else x=1;
            arr[i] = {pos[i],hts[i],x,i};
        }
        sort(arr.begin(),arr.end());
        s.push(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i][2]==1){s.push(arr[i]);continue;}
            int curr_h = arr[i][1];
            bool push=true;
            while(!s.empty() && s.top()[2]==1){
                if(curr_h>s.top()[1]){s.pop();curr_h-=1;arr[i][1]-=1;}
                else if(curr_h<s.top()[1]){s.top()[1]-=1;push=false;break;}
                else{s.pop();push=false;break;}
            }
            if(push)s.push(arr[i]);
        }
        
        arr.clear();
        vector<int> ans;
        while(!s.empty()){arr.push_back({s.top()[3],s.top()[1]});s.pop();}sort(arr.begin(),arr.end());
        
        for(auto v:arr){ans.push_back(v[1]);}
        return ans;
        
    }
};