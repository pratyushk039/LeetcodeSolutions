class Solution {
public:
    static bool comp(string & s1, string & s2){
        if(s1+s2>s2+s1){return true;}
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> st(nums.size());
        for(int i=0;i<nums.size();i++){
            st[i] = to_string(nums[i]);
        }
        sort(st.begin(),st.end(),comp);
        for(auto s:st){ans+=s;}
        bool b =true;
        for(char c:ans){if(c!='0'){b=false;break;}}
        if(b){return "0";}
        return ans;
    }
};