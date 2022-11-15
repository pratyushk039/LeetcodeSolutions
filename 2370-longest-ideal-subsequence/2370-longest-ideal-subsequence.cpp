class Solution {
public:
    //dp - bottom up!!!!!!!!!!
    int longestIdealString(string &s, int k) {
        int ans = 0;
        vector<int> dp(26,-1),vec(s.size(),-1);
        for(int i=0;i<s.size();i++){
            int curr = s[i] - 'a',maxima = 0;
            for(int j=0;j<26;j++){
                if(abs(curr-j)<=k){
                    maxima  = max(maxima , dp[j]);
                }
            }
            vec[i] = 1+maxima;
            dp[curr] = max(dp[curr],1+maxima);
            ans = max(ans,vec[i]);
        }
        return ans;
    }
};