class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)v.push_back(i);
        int start = 0;
        while(v.size()>1){
            int idx = (start+k-1)%v.size();
            int next = v[(idx+1)%v.size()];
            vector<int> v2;
            for(int i=0;i<v.size();i++){
                if(i!=idx){v2.push_back(v[i]);}
            }
            for(int i=0;i<v2.size();i++){if(v2[i]==next){start=i;}}
            v=v2;
        }
        return v[0];
    }
};