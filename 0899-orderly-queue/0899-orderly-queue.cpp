class Solution {
public:
    // very deep insight!!!!!! teaches to think small first in mathematical problems -> may lead to an early generalization!
    string orderlyQueue(string s, int k) {
        string ans = s;
        int n = s.size();
        if(k==1){
            for(int i=0;i<n;i++){
                char f = s[0];
                reverse(s.begin(),s.end());
                s.pop_back();
                reverse(s.begin(),s.end());
                s.push_back(f);
                ans = min(ans,s);}
            return ans;
        }
        else{
            sort(s.begin(),s.end());
            return s;
        }
    }
};