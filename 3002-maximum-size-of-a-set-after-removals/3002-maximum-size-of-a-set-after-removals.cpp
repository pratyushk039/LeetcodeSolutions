class Solution {
public:
    int maximumSetSize(vector<int>& ns1, vector<int>& ns2) {
        int n=ns1.size(),x=0,y=0;
        set<int> s;
        unordered_map<int,int>m1,m2;
        for(int i=0;i<n;i++){m1[ns1[i]]+=1;m2[ns2[i]]+=1;s.insert(ns1[i]);s.insert(ns2[i]);}
        for(auto it:m1){
            if(it.second>1){x+=(it.second-1);m1[it.first]=1;}
        }
        for(auto it:m2){
            if(it.second>1){y+=(it.second-1);m2[it.first]=1;}
        }
        // cout<<x<<" "<<y<<endl;
        for(auto it:m1){
            if(m2.find(it.first)!=m2.end()){if(n/2-x>n/2-y){x+=1;}else{y+=1;}}
        }
          // cout<<x<<" "<<y<<endl;
        int ans = s.size();
        if(x<n/2){ans-=(n/2-x);}
        if(y<n/2){ans-=(n/2-y);}
        return ans;
    }
};