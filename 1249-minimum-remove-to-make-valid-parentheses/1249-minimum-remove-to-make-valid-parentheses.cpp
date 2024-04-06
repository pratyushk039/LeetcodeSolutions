class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        int n=s.size();
        for(int i=0;i<n;i++){
            char inc = s[i];
            if(s[i]=='('){stack.push(i);}
            if(s[i]==')'){
                if(!stack.empty() && s[stack.top()]=='('){
                    stack.pop();
                }
                else{stack.push(i);}
            }
        }
        unordered_set<int> set;
        while(!stack.empty()){
            set.insert(stack.top());stack.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(set.find(i)!=set.end()){continue;}
            ans+=s[i];
        }
        return ans;
    }
};