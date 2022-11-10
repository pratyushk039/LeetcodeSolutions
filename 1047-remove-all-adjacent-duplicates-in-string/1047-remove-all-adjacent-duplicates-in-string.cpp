class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string a = "";
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==st.top()){st.pop();continue;}
            st.push(s[i]);
        }
        while(!st.empty()){
            a.push_back(st.top());st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};