class Solution {
public:
    string makeGood(string s) {
        vector<char> stack;
        for (auto currChar : s) {
            if (!stack.empty() && abs(stack.back() - currChar) == 32){stack.pop_back();} 
            else{stack.push_back(currChar);}
        }
        string ans(stack.begin(), stack.end());
        return ans;
    }
};