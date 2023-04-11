class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char> st;
        int k=0;
        for(char c:s){
            if(c=='*'){
                st.pop();
                k+=1;
            }
            else{
                st.push(c);
            }
        }
        if(k==0){return s;}
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};