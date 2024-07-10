class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        stack<string> st;
        st.push("main");
        for(auto c:logs){
            if(c=="../" && st.top()=="main"){continue;}
            if(c=="../"){if(st.size()>0)st.pop();}
            else if(c=="./")continue;
            else{st.push(c);}
        }
        return st.size()-1;
    }
};